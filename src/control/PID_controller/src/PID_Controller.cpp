#include "PID_Controller.h"

namespace Control
{
    /**
     * 参数初始化；收听和发布节点初始化。
    */
    PID_Controller::PID_Controller()
    {
        n.param("/pid_controller/wheelBase", wheelBase, 0.4);
        n.param("/pid_controller/Kp", Kp, 0.5);
        n.param("/pid_controller/Ki", Ki, 0.0);
        n.param("/pid_controller/Kd", Kd, 0.1);

        n.param("/pid_controller/MAX_ACCEL", MAX_ACCEL, 5.0);
        n.param("/pid_controller/MIN_ACCEL", MIN_ACCEL, -6.5);

        subTarArgs = n.subscribe("/final_control_cmd", 1, &PID_Controller::setTarget, this);
        subVehicleInfo = n.subscribe("/current_vehicle_can_info", 1, &PID_Controller::ctrlCallback, this);
        pubCmd = n.advertise<geometry_msgs::Vector3>("/carCmd", 1, true);
        time_1 = ros::Time::now().sec;
    }

    /**
     * 回调函数： 将（速度，角速度）转化为（速度，方向盘转角，档位）储存在TARGET中
     * @param twistMsg 规划得到的（速度，角速度）信息
    */
    void PID_Controller::setTarget(const control_msgs::control_req::ConstPtr &twistMsg)
    {
        float vel_req = twistMsg->Vel_req;          // m/s
        int gear_req = twistMsg->Gear_req;
        
        // for adas tracking
        float angle_req = twistMsg->Angle_req;      // degree
        angle_req = std::max(-400.0f, std::min(400.0f, angle_req));

        if (std::abs(vel_req - 0) <= 10e-5)
        {
            Target.D_R = gear_req;
            Target.targetSpd = 0;
            Target.targetAngle = 0;
        }
        else
        {
            Target.D_R = gear_req;
            Target.targetSpd = abs(vel_req);
            Target.targetAngle = angle_req;
        }

        Target.initialized = true;
    }

    /**
     * 回调函数： 收到车辆当前速度和铰接角; 根据TARGET,发送（加速度，方向盘转角，档位）
     * @param Msg 车辆当前速度，铰接角
    */
    void PID_Controller::ctrlCallback(const geometry_msgs::Twist &Msg)
    {
        if (!Target.initialized)
        {
            printf("Target Uninitialized!!\n");
            return;
        }

        Cmd.velocity = Target.targetSpd;
        // printf("target_speed: %lf\n", Target.targetSpd);
        Cmd.angle = Target.targetAngle;
        // printf("Target_Angle: %lf\n", Target.targetAngle);
        Cmd.D_R = Target.D_R;
 
        geometry_msgs::Vector3 vec;
        vec.x = Cmd.velocity;
        vec.y = Cmd.angle;
        vec.z = Cmd.D_R;

        pubCmd.publish(vec);
    }

}
