#include "plan.h"

adas_plan::adas_plan(ros::NodeHandle &nh) : nh_(nh)
{
    ROS_INFO("adas_plan initialization...");

    nh_.getParam("/map/latitude", latitude_);
    nh_.getParam("/map/longitude", longitude_);
    nh_.getParam("/map/height", height_);

    // 读取地图
    // GetRouteFromFile();

    // 接收 & 发送
    rtk_sub_ = nh_.subscribe("/Huace_rtk", 10, &adas_plan::RecvNavigationPosCallback, this);

    map_pub_ = nh_.advertise<nav_msgs::Path>("/rtk_map", 1, true);

    // init
    car_.velocity = 0.0;
    car_.heading = 0.0;
    car_.pitch = 0.0;
    car_.roll = 0.0;
    car_.longitude = 0.0;
    car_.latitude = 0.0;
    car_.height = 0.0;
    car_.x = 0.0;
    car_.y = 0.0;
    car_.z = 0.0;
    car_.gpstime = 0.0;
    car_.dist = 0.0;

    ROS_INFO("adas_plan Initialization finished.");
}

void adas_plan::GetRouteFromFile()
{
    char *home_path = getenv("HOME");
    char route_date_path[1024] = {0};
    sprintf(route_date_path, "%s" DATA_PATH "" DATA_NAME_REAL_ROUTE, home_path);
    ROS_INFO("route date path name:%s", route_date_path);

    FILE *route_data_read_fp = NULL;
    route_data_read_fp = fopen("/home/leiyubiao/dalian/src/tracking/adas/map/route_data.bin", "r");

    if (route_data_read_fp == NULL)
    {
        ROS_WARN("fail to open file !!!");
        exit(1);
    }
    else
    {
        ROS_INFO("Map file is open!");
        PositionConf p;
        while (!feof(route_data_read_fp))
        {
            fscanf(route_data_read_fp, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
                   &p.gpstime,
                   &p.x,
                   &p.y,
                   &p.z,
                   &p.longitude,
                   &p.latitude,
                   &p.height,
                   &p.heading,
                   &p.pitch,
                   &p.roll,
                   &p.velocity,
                   &p.dist);
            route_data_.push_back(p);
        }
        // 去除最后一个空行
        route_data_.pop_back();
        fclose(route_data_read_fp);

        printf("read %lu row, route_date is ok!\n", route_data_.size());
    }

    // for visualization
    geometry_msgs::PoseStamped map_pose;
    
    Eigen::Quaternion<double> q(1, 0, 0, 0);
    for (int i = 0; i < route_data_.size(); i++)
    {
        map_pose.header.frame_id = "/map";
        q = Eigen::AngleAxisd(route_data_[i].heading * M_PI / 180, Eigen::Vector3d::UnitZ()) *
            Eigen::AngleAxisd(route_data_[i].roll * M_PI / 180, Eigen::Vector3d::UnitY()) *
            Eigen::AngleAxisd(route_data_[i].pitch * M_PI / 180, Eigen::Vector3d::UnitX());
        map_pose.pose.orientation.x = q.x();
        map_pose.pose.orientation.y = q.y();
        map_pose.pose.orientation.z = q.z();
        map_pose.pose.orientation.w = q.w();
        map_pose.pose.position.x = route_data_[i].x;
        map_pose.pose.position.y = route_data_[i].y;
        map_pose.pose.position.z = route_data_[i].z;
        
        visual_map_.poses.push_back(map_pose);
    visual_map_.header.frame_id = "/map";
    visual_map_.header.stamp = ros::Time::now();
    map_pub_.publish(visual_map_);

    }

    // visual_map_.header.frame_id = "map";
}

void adas_plan::RecvNavigationPosCallback(const location_msgs::RTK &msg)
{
    // rtk msg to struct p
    car_.velocity = msg.velocity;

    car_.heading = msg.heading;
    car_.pitch = msg.pitch;
    car_.roll = msg.roll;

    car_.longitude = msg.longitude;
    car_.latitude = msg.latitude;
    car_.height = msg.height;

    car_.gpstime = msg.gpstime;
}

