#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H
#include <ros/ros.h>
#include <cmath>
#include <iostream>

#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/Vector3.h>
#include "location_msgs/RTK.h"
#include "control_msgs/control_req.h"

namespace Control
{

    struct targetArgs // 规划的状态量
    {
        double targetSpd;        // 目标速度
        double targetAngle;      // 目标方向盘转角
        int D_R{0};              // 目标车辆状态 0-停止 1-倒车 2-前进 # 0x0:P 0x1:R 0x2:N 0x3:D
        bool initialized{false}; // 是否初始化
    };

    struct cmdArgs // 控制量
    {
        double velocity; // 速度
        double angle; // 方向盘转角
        int D_R{0};   // 目标车辆状态 0-停止 1-倒车 2-前进
    };

    class PID_Controller
    {
    public:
        /**
         * 参数初始化；收听和发布节点初始化。
        */
        PID_Controller();

        ~PID_Controller(){};

        /**
         * 回调函数： 将（速度，角速度）转化为（速度，方向盘转角，档位）储存在TARGET中
         * @param twistMsg 规划得到的（速度，角速度）信息
        */
        void setTarget(const control_msgs::control_req::ConstPtr &twistMsg);

        /**
         * 回调函数： 收到车辆当前速度与铰接角; 根据TARGET,发送（加速度，方向盘转角，档位）
         * @param Msg 车辆当前速度,以及铰接角
        */
        void ctrlCallback(const geometry_msgs::Twist &Msg);

        /**
         * 速度反馈的PID纵向控制：返回车辆加速度
         * @param _Kp @param _Ki @param _Kd PID
         * @param _expSpd                   期望速度
         * @param _spdErr                   速度差 （期望速度-当前速度）
         * @param _spdDiff                  速度差的微分
         * @param _spdErrSum                速度差的积分
         * @param _preAccel                 上一时刻的加速度量
        */
        double longitudeControl(double _expSpd, double _spdErr, double _spdDiff, double _spdErrSum, double _preAccel);

    private:
        targetArgs Target; // 规划的状态量
        cmdArgs Cmd;       // 控制量

        double wheelBase; // 车身长度

        double Kp, Ki, Kd;       // PID
        double preSpdErr = 0;    // 上一时刻速度差
        double preSpdErrSum = 0; // 上一时刻速度差的积分

        double MAX_ACCEL; // 车辆最大加速度
        double MIN_ACCEL; // 车辆最小加速度
        // double expSpd; 测试用

        ros::NodeHandle n;
        ros::Subscriber subTarArgs; //target speed from planner
        ros::Subscriber subVehicleInfo;
        // ros::Subscriber subCurSpd;
        ros::Publisher pubCmd;
        double time_1;
    };
} // namespace Control
#endif
