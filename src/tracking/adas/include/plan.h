#ifndef PLAN_H
#define PLAN_H

#include <Eigen/Dense>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>
#include "location_msgs/RTK.h"
#include "adas_utils.h"

using namespace std;
class adas_plan
{
public:
    adas_plan(ros::NodeHandle &nh);
    ~adas_plan() {}

    // 读取地图
    void GetRouteFromFile();

    // 回调函数
    void RecvNavigationPosCallback(const location_msgs::RTK &msg);

    // 地图数据
    vector<PositionConf> route_data_;

    nav_msgs::Path visual_map_;

    // 目前位置
    PositionConf car_;

    // 可视化
    void Visualization();

private:

    // 地图原点
    double latitude_;
    double longitude_;
    double height_;

    // Subscriber and Publisher
    ros::NodeHandle nh_;
    ros::Subscriber rtk_sub_;
    // Visualization publisher
    ros::Publisher map_pub_;
    
};

#endif