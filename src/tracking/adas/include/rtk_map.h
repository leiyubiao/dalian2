#ifndef RTK_MAP_H
#define RTK_MAP_H
#include <ros/ros.h>
#include <vector>
#include "adas_utils.h"
#include "location_msgs/RTK.h"

using namespace std;

class rtk_map
{
public:
    rtk_map(ros::NodeHandle &nh);
    ~rtk_map() {}

 
    /**
     * @brief: 进入组合导航的回调函数
     * @param: msg: 采集的地图点数据
     * @param: velocity heading pitch roll longitude latitude height gpstime
     **/
    void recvNavigationPosCallback(const location_msgs::RTK &msg);

    /**
     * @brief: 保存采集的地图
     * @return:保存到预设的路径 
     **/
    void save2File();

    /**
     * @brief: 采集地图点
     **/
    void msgs2points();

    /**
     * @brief: 获取键盘操作
     **/
    int get_char();


private:

    // 惯导安装位置
    double insgps_x_;
    double insgps_y_;

    // 地图原点
    double latitude_;
    double longitude_;
    double height_;

    // 地图数据
    vector<PositionConf> route_data_;

    // 等间距采点后的索引
    vector<int> map_index_;
    PositionConf p_;

    // 采点距离
    double equal_length_;

    // 标志位
    int save_flag_;
    int start_record_flag_;

    // Subscriber and Publisher
    ros::NodeHandle nh_;
    ros::Subscriber rtk_sub_;
    ros::Publisher pub_;
};


#endif