#ifndef ADAS_CONTROL_H
#define ADAS_CONTROL_H
#include <ros/ros.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <assert.h>
#include <fstream>
#include <unistd.h>
#include "Eigen/Core"  //eigen部分
#include "Eigen/Dense" //稠密矩阵的代数运算
#include "Eigen/LU"
#include "Eigen/Geometry"
#include "data.h"
#include "json.hpp"

#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/Vector3.h>
#include "control_msgs/control_req.h"
#include "location_msgs/RTK.h"
#include "adas_utils.h"
#include "pid_control.h"


namespace control_space
{
    using namespace std;
    using namespace Eigen;
    using json = nlohmann::json;

    class ControllerBase
    {
    public:
        ControllerBase() {}
        virtual ~ControllerBase() {}

        /**
         * @brief: 用于计算车辆的前轮转角和速度，MPC LQR
         * @param: trajectory: 参考轨迹的信息
         * @param: vehicle_state_ptr: 车辆状态
         * @return: shared_ptr<VehicleCmd>: 车辆控制
         * @shared_ptr: 智能指针
         **/
        virtual void adas_tracking(const PositionConf &car_, const vector<PositionConf> &route_data_) = 0;

    };

    class Controller : public ControllerBase
    {
    public:

        /**
         * @brief:  最终计算前馈与反馈的角度
         * @param:  轨迹和车辆状态信息
         * @return: 计算期望转角和速度 
         **/
        Controller(ros::NodeHandle &nh);

        ~Controller() {}

        void adas_tracking(const PositionConf &car_, const vector<PositionConf> &route_data_) override;


        /**
         * @brief: 可视化
         * @param: 显示车辆位置点和最近点
         **/
        void Visualization(const PositionConf &xy_pos, const PositionConf &close_pos);

        int nearest_point_index_;                  // 最近点

        // 地图数据
        vector<PositionConf> route_data_;
        PositionConf xy_pos;               // 车辆前轴的XYZ位姿



    private:
       
        /**
         * @brief: 读取地图
         * @param: velocity heading pitch roll longitude latitude height
         **/
        void GetRouteFromFile();

        /**
         * @brief: 进入组合导航的回调函数
         * @param: msg: 采集的地图点数据
         * @param: 将组合导航采集的轨迹点赋给车辆
         **/
        void RecvNavigationPosCallback(const location_msgs::RTK &msg);
       

        /**
         * @brief : 地图原点的ENU坐标系->当前的车辆坐标系
         * @param : p地图点 xy_pos车辆位置位于地图的点
         * @return: p_veh车辆坐标系下点
         **/
        void Enu2veh(PositionConf &p_veh, const PositionConf &p, const PositionConf &xy_pos);     

        /**
         * @brief : 计算两个朝向角的夹角
         * @param : heading2 -> heading1 旋转的角度 -180 ~ 180 顺时针为正
         * @return: d_heading
         **/
        double ComputeDHeading(const double &heading1, const double &heading2);

        /**
         * @brief : 根据车辆前后两点计算朝向
         * @param : 地图点_p1_, _p2_
         * @return: heading
         **/
        double ComputeHeading(const PositionConf &_p1_, const PositionConf &_p2_);

        /**
         * @brief: 从参考轨迹中，找出最近点的序号,赋值给prior_index
         * @param: trajectory: 参考轨迹的信息
         * @param: vehicle_state_ptr: 车辆状态
         * @param: prior_index: 最近点序号的先验
         **/
        bool FindNearestPoint(const vector<PositionConf> &trajectory, PositionConf &vehicle_state, int &prior_index);

        /**
         * @brief: 找计算曲率半径的点
         * @param: prior_index: 最近点
         * @param: index_r1  index_r2  index_r3:路径上最近点附近的点，左边找一个间距点，右边找三个间距点，间距范围为dl
         * @param: prior_index: 最近点序号的先验
         **/
        void findPoints2ComputeRadius(const int &prior_index, int &index_r1, int &index_f1, int &index_f2, int &index_f3, const vector<PositionConf> &route_data_);

        /**
         * @brief: 根据三点坐标求曲率
         * @param: prior_index: 最近点
         * @param: index_r1  index_r2  index_r3:路径上最近点附近的点，左边找一个间距点，右边找三个间距点，间距范围为dl
         * @return:最近点处转弯半径
         **/
        double CalculateRadius(double x1, double y1, double x2, double y2, double x3, double y3);

        /**
         * @brief: 计算铰接角速度
         * @param: ref_point_ptr：参考轨迹
         * @param: vehicle_state_ptr：车辆当前状态
         * @return:铰接角速度
         **/
        double ComputeArticulatedAngleSpd(const PositionConf ref_point_ptr, const PositionConf vehicle_state_ptr);

        /**
         * @brief: 获取铰接角
         * @param: msg
         * @return:铰接角
         **/
        void AngleCallback(const geometry_msgs::Twist &msg);
        
        // /**
        //  * @brief: 可视化
        //  * @param: 显示车辆位置点和最近点
        //  **/
        // void Visualization(const PositionConf &xy_pos, const PositionConf &close_pos);



        // 车辆参数
        double L1_;                                // 铰接点至车头质心距离
        double L2_;                                // 铰接点至车尾质心距离
        double ts_;                                // 车辆控制时间
        double steer_max_degree;                    // 单侧最大转动角度

        double k1_;                                // 控制模型里常数k1
        double k2_;                                // 控制模型里常数k2

        double ka_;                                // paper
        double kb_;                                //  atan2

        double sys_delay_;                         // 延迟
        // int nearest_point_index_;                  // 最近点
        double radius;                             // 最近点转弯半径

        // 判断车辆速度进入前进后退
        // int close_index;
        
        // 惯导安装位置
        double insgps_x_;
        double insgps_y_;

        // 地图原点 
        double longitude_;
        double latitude_;
        double height_;

        double max_speed_;
        double min_speed_ ;

        // 地图数据
        // vector<PositionConf> route_data_;
        nav_msgs::Path visual_map_;
        
        // 车辆当前位置
        PositionConf car_;
        double car_angle_;

        // PID参数
        PIDControl pid_control_angle_;
        PIDControl pid_control_speed_;
        PIDConf pid_conf_angle_;
        PIDConf pid_conf_speed_;

        double control_angle_;
        double previous_control_angle_;
        double control_speed_;

        // Subscriber and Publisher
        ros::NodeHandle nh_;
        ros::Subscriber subTarArgs_;
        ros::Subscriber rtk_sub_;
        ros::Subscriber subCurAngle;
        
        // ros::Publisher pubCmd;
        ros::Publisher control_pub_;

        // Visualization publisher
        ros::Publisher Map_pub_;
        ros::Publisher Pose_car_pub_;
        ros::Publisher Pose_close_pub_;

    };

}
#endif

