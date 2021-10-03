#include "adas_control.h"
#include "rounge_kutta.h"

namespace control_space
{
    Controller::Controller(ros::NodeHandle &nh) : nh_(nh), 
                                                  nearest_point_index_(-1)
    {
        ROS_INFO("LateController Initializing...");

        nh_.getParam("/calibration/insgps_x", insgps_x_);
        nh_.getParam("/calibration/insgps_y", insgps_y_);
        nh_.getParam("/map/latitude", latitude_);
        nh_.getParam("/map/longitude", longitude_);
        nh_.getParam("/map/height", height_);
        nh_.getParam("/control/vehicle_param/L1", L1_);
        nh_.getParam("/control/vehicle_param/L2", L2_);
        nh_.getParam("/control/k1", k1_);
        nh_.getParam("/control/k2", k2_);
        nh_.getParam("/control/ka", ka_);
        nh_.getParam("/control/kb_", kb_);
        nh_.getParam("/control/vehicle_param/steer_max_degree", steer_max_degree);
        nh_.getParam("/control/max_speed", max_speed_);
        nh_.getParam("/control/min_speed", min_speed_);

        // 接收铰接角
        subCurAngle = nh_.subscribe("/current_vehicle_can_info", 1, &control_space::Controller::AngleCallback, this);
       
        control_pub_ = nh_.advertise<control_msgs::control_req>("/final_control_cmd", 10, true);

        Map_pub_ = nh.advertise<nav_msgs::Path>("/rtk_map", 1);
        Pose_car_pub_ = nh.advertise<nav_msgs::Odometry>("/rtk_car", 1);
        Pose_close_pub_ = nh.advertise<nav_msgs::Odometry>("/rtk_close_point", 1);

        // 设置PID参数
        // 横向控制
        double lateral_kp;
        double lateral_ki;
        double lateral_kd;
        nh_.getParam("/control/lateral/kp", lateral_kp);

        // printf("lateral_kp: %lf\n", lateral_kp);
        nh_.getParam("/control/lateral/ki", lateral_ki);
        nh_.getParam("/control/lateral/kd", lateral_kd);
        pid_conf_angle_.kp = lateral_kp;
        pid_conf_angle_.ki = lateral_ki;
        pid_conf_angle_.kd = lateral_kd;
        pid_conf_angle_.kaw = 0;
        pid_control_angle_.init(pid_conf_angle_);

        // 纵向控制
        double velocity_kp;
        double velocity_ki;
        double velocity_kd;
        nh_.getParam("/control/velocity/kp", velocity_kp);
        nh_.getParam("/control/velocity/ki", velocity_ki);
        nh_.getParam("/control/velocity/kd", velocity_kd);
        pid_conf_speed_.kp = velocity_kp;
        pid_conf_speed_.ki = velocity_ki;
        pid_conf_speed_.kd = velocity_kd;
        pid_conf_speed_.kaw = 0;
        pid_control_speed_.init(pid_conf_speed_);

        // 车辆状态信息初始化
        car_.velocity = 0;
        car_.heading = 0;
        car_.pitch = 0;
        car_.roll = 0;
        car_.longitude = 0;
        car_.latitude = 0;
        car_.height = 0;
        car_.x = 0;
        car_.y = 0;
        car_.z = 0;
        car_.gpstime = 0;
        car_.dist = 0;

        ROS_INFO("Lateral Controller Initialization Finished.");
    }

    
    void Controller::Enu2veh(PositionConf &p_veh, const PositionConf &p, const PositionConf &xy_p)
    {
        positionConf_copy(p, p_veh);
        p_veh.x = (p.x - xy_p.x) * cos(xy_p.heading * M_PI / 180) -
                (p.y - xy_p.y) * sin(xy_p.heading * M_PI / 180);
        p_veh.y = (p.x - xy_p.x) * sin(xy_p.heading * M_PI / 180) +
                (p.y - xy_p.y) * cos(xy_p.heading * M_PI / 180);
        p_veh.z = p.z;
    }


    double Controller::ComputeDHeading(const double &heading1, const double &heading2)
    {
        double d_heading = 0;
        if (heading1 > (heading2 + 180))
        {
            d_heading = heading1 - heading2 - 360;
        }
        else if (heading1 < (heading2 - 180))
        {
            d_heading = 360 - (heading2 - heading1);
        }
        else
        {
            d_heading = heading1 - heading2;
        }

        return d_heading;
    }


    double Controller::ComputeHeading(const PositionConf &_p1_, const PositionConf &_p2_)
    {
        double heading = 0;
        if(_p1_.x == _p2_.x)
        {
            if(_p2_.y >= _p1_.y)
            {
                heading = 0;
            }
            else
            {
                heading = 180;
            }
        }
        else
        {
            if(atan((_p1_.y - _p2_.y)/(_p1_.x - _p2_.x)) == 0)
            {
                if(_p1_.x > _p2_.x)
                {
                    heading = 270;
                }
                else
                {
                    heading = 90;
                }
            }
            else
            {
                if(_p2_.x > _p1_.x)     //一四象限
                {
                    if(_p2_.y > _p1_.y) //一象限
                    {
                        heading = 90 - atan((_p1_.y - _p2_.y)/(_p1_.x - _p2_.x))*180/M_PI;
                    }
                    else                //四象限
                    {
                        heading = 90 - atan((_p1_.y - _p2_.y)/(_p1_.x - _p2_.x))*180/M_PI;
                    }
                }
                else                    //二三像限
                {
                    if(_p2_.y > _p1_.y) //二象限
                    {
                        heading = 270 - atan((_p1_.y - _p2_.y)/(_p1_.x - _p2_.x))*180/M_PI;
                    }
                    else                //三象限
                    {
                        heading = 270 - atan((_p1_.y - _p2_.y)/(_p1_.x - _p2_.x))*180/M_PI;
                    }
                }
            }
        }

        return heading;
    }


    void Controller::Visualization(const PositionConf &xy_pos, const PositionConf &close_pos)
    {

        Eigen::Quaternion<double> q(1, 0, 0, 0);
        nav_msgs::Odometry map_pose;
        map_pose.header.frame_id = "map";
        map_pose.header.stamp = ros::Time::now();

        q = Eigen::AngleAxisd(close_pos.heading * M_PI / 180, Eigen::Vector3d::UnitZ()) *
        Eigen::AngleAxisd(close_pos.roll * M_PI / 180, Eigen::Vector3d::UnitY()) *
        Eigen::AngleAxisd(close_pos.pitch * M_PI / 180, Eigen::Vector3d::UnitX());
        map_pose.pose.pose.orientation.x = q.x();
        map_pose.pose.pose.orientation.y = q.y();
        map_pose.pose.pose.orientation.z = q.z();
        map_pose.pose.pose.orientation.w = q.w();
        map_pose.pose.pose.position.x = close_pos.x;
        map_pose.pose.pose.position.y = close_pos.y;
        map_pose.pose.pose.position.z = close_pos.z;
        Pose_close_pub_.publish(map_pose);

        q = Eigen::AngleAxisd(xy_pos.heading * M_PI / 180, Eigen::Vector3d::UnitZ()) *
            Eigen::AngleAxisd(xy_pos.roll * M_PI / 180, Eigen::Vector3d::UnitY()) *
            Eigen::AngleAxisd(xy_pos.pitch * M_PI / 180, Eigen::Vector3d::UnitX());
        map_pose.pose.pose.orientation.x = q.x();
        map_pose.pose.pose.orientation.y = q.y();
        map_pose.pose.pose.orientation.z = q.z();
        map_pose.pose.pose.orientation.w = q.w();
        map_pose.pose.pose.position.x = xy_pos.x;
        map_pose.pose.pose.position.y = xy_pos.y;
        map_pose.pose.pose.position.z = xy_pos.z;
        Pose_car_pub_.publish(map_pose);
        
    }


    void Controller::findPoints2ComputeRadius(const int &prior_index, int &index_r1, int &index_f1, int &index_f2, int &index_f3, const vector<PositionConf> &route_data_)
    {
        // FIXME:   
        // double equal_l = (center2frontaxis + center2rearaxis)/2;
        // 按照上面公式才1.34，可以放大为2
        double equal_l = 2;
        double l = 0;
        int down, up;

        // 寻找后面的点
        l = 0;
        down = prior_index;
        up = prior_index;
        while (l < equal_l)
        {
            if (up == 0)
                break;
            down = up - 1;
            double x1 = route_data_[down].x;
            double y1 = route_data_[down].y;
            double x2 = route_data_[up].x;
            double y2 = route_data_[up].y;
            l += sqrt(data_space::PointDistanceSquare(x1, y1, x2, y2));
            up--;
        }
        index_r1 = down;
        
        // 寻找前面点1
        l = 0;
        down = prior_index;
        up = prior_index;
        while (l < equal_l)
        {
            if (down == route_data_.size() - 1)
                break;
            up = down + 1;
            double x1 = route_data_[down].x;
            double y1 = route_data_[down].y;
            double x2 = route_data_[up].x;
            double y2 = route_data_[up].y;
            l += sqrt(data_space::PointDistanceSquare(x1, y1, x2, y2));
            down++;
        }
        index_f1 = up;

        // 寻找前面点2
        l = 0;
        down = prior_index;
        up = prior_index;
        while (l < equal_l * 2)
        {
            if (down == route_data_.size() - 1)
                break;
            up = down + 1;
            double x1 = route_data_[down].x;
            double y1 = route_data_[down].y;
            double x2 = route_data_[up].x;
            double y2 = route_data_[up].y;
            l += sqrt(data_space::PointDistanceSquare(x1, y1, x2, y2));
            down++;
        }
        index_f2 = up;

        // 寻找前面点3 
        l = 0;
        down = prior_index;
        up = prior_index;
        while (l < equal_l * 3)
        {
            if (down == route_data_.size() - 1)
                break;
            up = down + 1;
            double x1 = route_data_[down].x;
            double y1 = route_data_[down].y;
            double x2 = route_data_[up].x;
            double y2 = route_data_[up].y;
            l += sqrt(data_space::PointDistanceSquare(x1, y1, x2, y2));
            down++;
        }
        index_f3 = up;
    }


    double Controller::CalculateRadius(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        double a = 2 * (x2 - x1);
        double b = 2 * (y2 - y1);
        double c = x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1;
        double d = 2 * (x3 - x2);
        double ee = 2 * (y3 - y2);
        double f = x3 * x3 + y3 * y3 - x2 * x2 - y2 * y2;
        double r;
        double r_max = 500;
        if ((b * d - ee * a) == 0)
        {
            r = r_max;
        }
        else
        {
            double x = (b * f - ee * c) / (b * d - ee * a);
            double y = (d * c - a * f) / (b * d - ee * a);
            r = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
            if (r >= r_max)
            {
                r = r_max;
            }
        }

        // 确定R的正负
        double dx1 = x2 - x1;
        double dy1 = y2 - y1;
        double theta1 = atan2(dy1, dx1);
        data_space::NormalizeRad(theta1);
        double dx2 = x3 - x1;
        double dy2 = y3 - y1;
        double theta2 = atan2(dy2, dx2);
        data_space::NormalizeRad(theta2);

        double dtheta = theta2 - theta1;
        if (dtheta >= M_PI)
        {
            dtheta = -(2 * M_PI - dtheta);
        }
        else if (dtheta <= -M_PI)
        {
            dtheta = dtheta + 2 * M_PI;
        }
        if (dtheta < 0)
        {
            r *= -1;
        } // 夹角之间有正负数，是 -pi~pi之间的数。

        /********************* 网上教程的计算结果***********************/
        Eigen::MatrixXd A(3, 3);
        Eigen::MatrixXd B(3, 3);
        Eigen::MatrixXd C(3, 3);

        return r;
    }
 
    
    bool Controller::FindNearestPoint(const vector<PositionConf> &trajectory, PositionConf &vehicle_state, int &prior_index)
    {

        if (trajectory.empty())
        {
            ROS_ERROR("ERROR IN FINDING NEAREST POINT!!!");
            return false;
        }

        bool nearest_point_is_found = false;
        int search_index_upper = trajectory.size() - 1;
        int search_index_lower = 0;

        if (prior_index != -1)
        {
            // DEBUG search_range参数可能需要调整
            int search_range = 50;
            search_index_lower = (prior_index - search_range) > 0 ? (prior_index - search_range) : 0;
            search_index_upper = (prior_index + search_range) < (trajectory.size() - 1) ? (prior_index + search_range) : (trajectory.size() - 1);
        }

        double min_distance = DBL_MAX;
        double distance_tmp = 0.0;
        for (int i = search_index_lower; i <= search_index_upper; i++)
        {
            double x1 = vehicle_state.x;
            double y1 = vehicle_state.y;
            double x2 = trajectory[i].x;
            double y2 = trajectory[i].y;
            distance_tmp = data_space::PointDistanceSquare(x1, y1, x2, y2);

            prior_index = distance_tmp < min_distance ? i : prior_index;
            min_distance = distance_tmp < min_distance ? distance_tmp : min_distance;
        }

        if (prior_index >= search_index_lower && prior_index <= search_index_upper) 
        {
            nearest_point_is_found = true;
        }
        else
        {
            prior_index = -1;
            ROS_WARN("CANNOT FIND NEAREST POINT!!!");
        }

        return nearest_point_is_found;
    }


    void Controller::adas_tracking(const PositionConf &car_, const vector<PositionConf> &route_data_)
    {

        if(car_.longitude == 0)
            return;

        // 临时变量
        // PositionConf car_lla;              // 组合导航传来的组合导航经纬度位姿

        // v-车辆坐标系
        // n-最近点
        PositionConf vn_xy_pos;            // 最近点在车辆坐标系下的位姿
        // 组合导航传来的经纬度位姿拷贝给车辆
        positionConf_copy(car_, xy_pos);

        // 坐标变换 LLA坐标->全局XYZ位姿
        gps2xy(xy_pos, longitude_, latitude_, height_);
        ROS_ERROR("x = %lf", xy_pos.x);

        // 惯导坐标系-> 车辆前轴中心坐标系
        insgps2center(xy_pos, insgps_x_, insgps_y_);
        
        // 找最近点, nearest_point_index_ 理论上的车辆中心最近点,作为成员变量存储做下一帧的先验
        bool is_found = FindNearestPoint(route_data_, xy_pos, nearest_point_index_);

        if(!is_found)
        {
            printf("!!!Not find nearestPoint!!!");
        }

        /*
        // 根据获取的最近点nearest_point_index_找到附近点，并求解最近点的转弯半径
        int index_r1, index_f1, index_f2, index_f3;
        findPoints2ComputeRadius(nearest_point_index_, index_r1, index_f1, index_f2, index_f3, route_data_);
        // 计算曲率半径,算三次取最小
        double index_nearest_x = route_data_[nearest_point_index_].x;
        double index_nearest_y = route_data_[nearest_point_index_].y;
        double index_r1_x = route_data_[index_r1].x;
        double index_r1_y = route_data_[index_r1].y;
        double index_f1_x = route_data_[index_f1].x;
        double index_f1_y = route_data_[index_f1].y;
        double index_f2_x = route_data_[index_f2].x;
        double index_f2_y = route_data_[index_f2].y;
        double index_f3_x = route_data_[index_f3].x;
        double index_f3_y = route_data_[index_f3].y;
        double R1 = CalculateRadius(index_nearest_x, index_nearest_y, index_r1_x, index_r1_y, index_f1_x, index_f1_y);
        double R4 = CalculateRadius(index_nearest_x, index_nearest_y, index_f1_x, index_f1_y, index_f2_x, index_f2_y);
        double R5 = CalculateRadius(index_f1_x, index_f1_y, index_f2_x, index_f2_y, index_f3_x, index_f3_y);
        radius = R1;
        radius = radius < R4 ? radius : R4;
        radius = radius < R5 ? radius : R5;
        */

    
        // 将最近点的坐标转换到车辆坐标系下
        // Enu2veh(vn_xy_pos, route_data_[nearest_point_index_], xy_pos);  
        nearest_point_index_ += 5;  // FIXME: 可以更改预瞄点的个数，改善直线循迹效果
        int upper_index = route_data_.size();
        nearest_point_index_ = min(nearest_point_index_, upper_index - 1);

        vn_xy_pos.x = route_data_[nearest_point_index_].x;
        vn_xy_pos.y = route_data_[nearest_point_index_].y;
        vn_xy_pos.heading = route_data_[nearest_point_index_].heading;
        vn_xy_pos.velocity = route_data_[nearest_point_index_].velocity;

        // printf("nearest_point : %d\n", nearest_point_index_);
        // printf("nearest_point_velocity: %lf\n", route_data_[nearest_point_index_].velocity);
        
        // 根据最近点找到轨迹上的点
        // int over_look_index = nearest_point_index_ + 20;
        // int upper_index = route_data_.size();
        // over_look_index = min(over_look_index, upper_index -1);
        // vn_xy_pos.velocity = route_data_[over_look_index].velocity;

        // 求解轨迹点和车辆位置的横向误差，航向误差
        // vn_xy_pos.heading = 3.1415926 /  2 - vn_xy_pos.heading; 
        // double lateralErr = (xy_pos.y - vn_xy_pos.y) * cos(vn_xy_pos.heading) - (xy_pos.x - vn_xy_pos.x) * sin(vn_xy_pos.heading);
        // double headingErr = xy_pos.heading - vn_xy_pos.heading;
        // headingErr = -headingErr;

        double headingErr = vn_xy_pos.heading - xy_pos.heading;
        headingErr = headingErr / 180.0 * M_PI;
        vn_xy_pos.heading = M_PI / 2.0 - vn_xy_pos.heading / 180.0 * M_PI;  // FIXME: 是否可以直接用 M_PI/2 减？
        xy_pos.heading = M_PI / 2.0 - xy_pos.heading / 180.0 * M_PI;
        // double lateralErr = vn_xy_pos.y * cos(vn_xy_pos.heading) - vn_xy_pos.x * sin(vn_xy_pos.heading);
        double lateralErr = (xy_pos.y - vn_xy_pos.y) * cos(vn_xy_pos.heading) - (xy_pos.x - vn_xy_pos.x) * sin(vn_xy_pos.heading);
        // printf("xy_pos_x = %lf, vn_xy_pos_x = %lf\n", xy_pos.x, vn_xy_pos.x);
        // printf("xy_pos_y = %lf, vn_xy_pos_y = %lf\n", xy_pos.y, vn_xy_pos.y);
        // printf("xy_pos_heading = %lf, vn_xy_pos_heading = %lf\n", xy_pos.heading, vn_xy_pos.heading);

        // printf("headingErr: %lf\n", headingErr);
        // printf("lateralErr: %lf\n", lateralErr);

        // 根据调试看是否需要给headingErr限幅
        while(headingErr > M_PI)
        {
            headingErr -= 2 * M_PI;
        }
        while(headingErr < - M_PI)
        {
            headingErr += 2 * M_PI;
        }

        double articulated_angle;
        double v = xy_pos.velocity;
        // printf("v:::%lf\n", v);
        double ref_curvature = 1 / (radius);

        // 铰接车运动学模型
        // TODO: 考虑曲率情况
        // double t1 = v * cos(headingErr) / ( radius - lateralErr) - k2_* headingErr - k1_ * lateralErr * v * sin(headingErr) / headingErr;
        // double t2 = t1 * L1_ / L2_ ;
        // double t3 = - v / L2_;
        // printf("t1: %lf\n", t1);
        // printf("t2: %lf\n", t2);
        // printf("t3: %lf\n", t3);
        // shared_ptr<ToSolveBase> toSolvePrt = make_shared<Example>();
        // shared_ptr<OdmSolve> odmSolverPtr = make_shared<OdmSolve>(toSolvePrt);
        // vector<double> tspace {0.0, 1.0};
        // vector<double> initNum {car_angle_};
        // double h = 0.01;
        // articulated_angle = odmSolverPtr->GetAns(tspace, initNum, h, t1, t2, t3);
        // printf("car_angle_: %lf\n", car_angle_);

        // TODO: 不考虑曲率情况
        double t1 = - k1_ * v * (L1_+L2_) * lateralErr / L2_;
        double t2 = - k2_ * (L1_+L2_) * headingErr / L2_;
        double t3 = - v / L2_;

        // printf("t1: %lf\n", t1);
        // printf("t2: %lf\n", t2);
        // printf("t3: %lf\n", t3);

        shared_ptr<ToSolveBase> toSolvePrt = make_shared<Example>();
        shared_ptr<OdmSolve> odmSolverPtr = make_shared<OdmSolve>(toSolvePrt);
        vector<double> tspace {0.0, 1.0};
        car_angle_ = -car_angle_ * M_PI / 180.0; // 转弧度进行计算
        double h = 0.01;
        articulated_angle = odmSolverPtr->GetAns(tspace, car_angle_, h, t1, t2, t3);

        articulated_angle = -articulated_angle * 180.0 / M_PI; // 输出给底层的是角度，而非弧度。
        double angle2;
        double angleTmp;
        int indexPre = nearest_point_index_ + 5;
        int sizeRoute = route_data_.size() - 1;
        indexPre = min(indexPre, sizeRoute);
        angleTmp = atan2f(route_data_[indexPre].y, route_data_[indexPre].x) * 180.0 / M_PI;
        if (angleTmp >0.0 and angleTmp <= 90.0) {
            angleTmp = 90.0- angleTmp;
        } else if (angleTmp < 0.0) angleTmp = 90.0 - angleTmp;
        else angleTmp = 450.0 - angleTmp;

        angle2 = angleTmp - xy_pos.heading;
        articulated_angle = ka_ * articulated_angle + kb_ * angle2;
        printf("car_angle_: %lf\n", car_angle_);
        double target_steering_angle = data_space::Clamp(articulated_angle, -steer_max_degree, steer_max_degree);
        printf("Angle: articulated_angular %3lf\n", target_steering_angle);
        

        // 最后输出量为速度和转角,角度。暂时是左负右正，后续改成左正右.
        control_msgs::control_req control_cmd;
        control_cmd.Angle_req = target_steering_angle;
        control_cmd.Vel_req = vn_xy_pos.velocity;
        
        // 档位设置
        if (std::abs(vn_xy_pos.velocity - 0) <= 10e-5)
            control_cmd.Gear_req = 0;
        else if (vn_xy_pos.velocity < 0)
            control_cmd.Gear_req = 2;
        else
            control_cmd.Gear_req = 1;

        // 到达终点
        if (route_data_.size() - nearest_point_index_ <= 3)
        {
            control_cmd.Angle_req = 0;
            control_cmd.Vel_req = 0;
            control_cmd.Gear_req = 1;
            ROS_INFO("Arrived the ending point !!! ...");
        }

        // publish
        control_pub_.publish(control_cmd);
        // visualization
        Visualization(xy_pos, route_data_[nearest_point_index_]);
    }


    void Controller::AngleCallback(const geometry_msgs::Twist &msg)
    {
        car_angle_ = msg.angular.x;
    }

}

double OdmSolve::GetAns(const vector<double>& tspace, double initNum, const double h, double k1, double k2, double k3) const 
{
    int size = tspace.size();
    assert(size==2);
    double startTime = tspace[0];
    double endTime = tspace[1];
    assert(endTime > startTime);
    int loopTime = (endTime - startTime) / h; // 循环100次
    vector<double> k(4, 0.0);
    vector<double> y(loopTime + 1);

    // y[0] = *initNum.begin();
    y[0] = initNum;

    for (int i = 0; i < loopTime; ++i) {
        double t = startTime +  static_cast<double>(i * h);
        k[0] = ToSolveBasePtr_->function(t, y[i], k1, k2, k3);
        k[1] = ToSolveBasePtr_->function(t + h / 2.0, y[i] + h / 2.0 * k[0], k1, k2, k3);
        k[2] = ToSolveBasePtr_->function(t + h / 2.0, y[i] + h / 2.0 * k[1], k1, k2, k3);
        k[3] = ToSolveBasePtr_->function(t + h, y[i] + h * k[2], k1, k2, k3);
        y[i + 1] = y[i] + h / 6.0 * (k[0] + 2 * k[1] + 2 * k[2] + k[3]);
        // cout<<"i = "<<i<<" y = "<<y[i]<<endl;
    }
    // cout << "y[1] = " << y[1] << endl;
    // cout << "y[9] = " << y[9] << endl;
    // cout << "y[19] = " << y[9] << endl;
    // cout << "y[29] = " << y[1] << endl;
    // cout << "y[39] = " << y[9] << endl;
    // cout << "y[49] = " << y[9] << endl;
    // cout << "y[59] = " << y[1] << endl;
    // cout << "y[69] = " << y[9] << endl;
    // cout << "y[79] = " << y[9] << endl;
    // cout << "y[89] = " << y[9] << endl;
    // cout << "y[99] = " << y[9] << endl;
    return y[50];
}