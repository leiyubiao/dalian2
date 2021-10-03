#include "rtk_map.h"

rtk_map::rtk_map(ros::NodeHandle &nh) : nh_(nh)
{
    // load paramaters from yaml
    ROS_INFO("Start to load paramaters from yaml...");
    nh_.getParam("/calibration/insgps_x", insgps_x_);
    nh_.getParam("/calibration/insgps_y", insgps_y_);

    nh_.getParam("/map/latitude", latitude_);
    nh_.getParam("/map/longitude", longitude_);
    nh_.getParam("/map/height", height_);

    nh_.getParam("/map/equal_length", equal_length_);
    ROS_INFO("Paramaters loading finished.");

    // flags
    save_flag_ = 0;
    start_record_flag_ = 0;

    // init
    p_.velocity = 0;
    p_.heading = 0;
    p_.pitch = 0;
    p_.roll = 0;
    p_.longitude = 0;
    p_.latitude = 0;
    p_.height = 0;
    p_.x = 0;
    p_.y = 0;
    p_.z = 0;
    p_.gpstime = 0;
    p_.dist = 0;

    rtk_sub_ = nh_.subscribe("/Huace_rtk", 30, &rtk_map::recvNavigationPosCallback, this);
    ROS_INFO("Initialization finished and enter loop.");
    
    msgs2points();
}


void rtk_map::msgs2points()
{
    ros::Rate loop_rate(FRE); // FRE为更新频率
    ROS_INFO("s->enter, start to get point data; c->enter, finish to get point data");

    while (ros::ok())
    {
        // 获取键盘输入: ASCII(115): s  ASCII(99): c  
        // TODO: 启动采图程序后，s回车->开始采图 c回车->结束采图  
        int ret = get_char();
        if (ret == 115)
        {
            ROS_INFO("Start get route point from GPS");
            start_record_flag_ = 1;
        }
        if (ret == 99)
        {
            ROS_INFO("Save route file");
            start_record_flag_ = 0;
            save_flag_ = 1;
        }

        // 完成采集输出地图文件
        if (save_flag_ == 1)
        {
            ROS_INFO("save route data!\n");
            rtk_map::save2File();
            break;
        }

        ros::spinOnce();
        loop_rate.sleep();
    }

    ROS_INFO("map saved!\n");
    ros::shutdown();
}


void rtk_map::save2File()
{
    FILE *route_data_save_fp = NULL;
    char end1 = 0x0d; // "/n"
    char end2 = 0x0a;

    // 存储路径
    char *home_path = getenv("HOME");
    char route_date_path[1024] = {0};
    sprintf(route_date_path, "%s" DATA_PATH "" DATA_NAME_REAL_ROUTE, home_path);
    ROS_INFO("route date path name:%s", route_date_path);

    route_data_save_fp = fopen(route_date_path, "w+");
    if (route_data_save_fp == NULL)
    {
        ROS_WARN("fail to open file !!!");
        exit(1);
    }

    if (route_data_.size() == 0)
    {
        ROS_WARN("no data recorded!!!");
        exit(1);
    }

    // 计算里程
    route_data_[0].dist = 0;
    for (int i = 1; i < route_data_.size(); i++)
    {
        double dx = route_data_[i].x - route_data_[i - 1].x;
        double dy = route_data_[i].y - route_data_[i - 1].y;
        route_data_[i].dist = route_data_[i - 1].dist + sqrt(dx * dx + dy * dy);
    }

    // 等间距采点的索引
    map_index_.push_back(0);

    double dist = 0;
    int index = 1;
    while (index < route_data_.size())
    {
        dist = route_data_[index].dist - route_data_[map_index_.back()].dist;
        if (dist > equal_length_)
            map_index_.push_back(index);
        index++;
    }

    //写入文件
    printf("the num of points in map : %d \n", (int)map_index_.size());
    for (int i = 0; i < map_index_.size(); i++)
    {
        int j = map_index_[i];
        fprintf(route_data_save_fp, "%.3lf %.2lf %.2lf %.2lf %.8lf %.8lf %.3lf %.2lf %.2lf %.2lf %.2lf %.2lf %c",
                route_data_[j].gpstime,
                route_data_[j].x,
                route_data_[j].y,
                route_data_[j].z,
                route_data_[j].longitude,
                route_data_[j].latitude,
                route_data_[j].height,
                route_data_[j].heading,
                route_data_[j].pitch,
                route_data_[j].roll,
                route_data_[j].velocity,
                route_data_[j].dist,
                end2);
    }

    fclose(route_data_save_fp);
}


int rtk_map::get_char()
{
    // TODO: 设置参数
    fd_set rfds;
    struct timeval tv;
    int ch = 0;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 0;
    tv.tv_usec = 10; //设置等待超时时间

    //检测键盘是否有输入
    if (select(1, &rfds, NULL, NULL, &tv) > 0)
    {
        ch = getchar();
    }

    return ch;
}


void rtk_map::recvNavigationPosCallback(const location_msgs::RTK &msg)
{
    // rtk msg to struct p
    p_.velocity = msg.velocity;
    p_.heading = msg.heading;
    p_.pitch = msg.pitch;
    p_.roll = msg.roll;
    p_.longitude = msg.longitude;
    p_.latitude = msg.latitude;
    p_.height = msg.height;
    p_.gpstime = msg.gpstime;

    // 采集地图点，并把采集的地图点转成车辆坐标系下的点存到route_data_里
    if (start_record_flag_ == 1)
    {
        gps2xy(p_, longitude_, latitude_, height_);
        insgps2center(p_, insgps_x_, insgps_y_);
        if (route_data_.size() == 0)
            route_data_.push_back(p_);
        else
        {
            if (p_.longitude != route_data_.back().longitude || p_.latitude != route_data_.back().latitude)
                route_data_.push_back(p_);
        }
    }
}
