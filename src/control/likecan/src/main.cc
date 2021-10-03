#define CAN_Device USBCAN_E_1CH
#include <iostream>
#include <ros/ros.h>
#include "CanMsgDefs.h"
#include "CanCommonFcn.h"
#include "CanHandler.h"
#include "ICANCmd.h"
#include "canstream.h"
#include "rtknavigation.h"
#include "uwb.h"
#include "math.h"

#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Twist.h>


using namespace CanProcess;

DWORD dwDeviceHandle1;
DWORD dwDeviceHandle2;
CAN_InitConfig config;
std::vector<canstreamPtr> vcanstreamPtr;

// 第一次触发方向盘控制
bool first_hit = true;

// 定义状态全局变量
double global_curSpd = 0.0;
double global_curAngle = 0.0;
double global_curBrake = 0.0;

//转角PID
double TargetAngle;    //定义设定值
double err_last = 0.0; //定义上一个偏差值
double err_last_last = 0.0;
double increment = 0.0;
double voltage = 0.0;  //定义控制执行器变量

// 定义控制全局变量
double global_cmd_spd;
double global_cmd_angle;
int global_cmd_D_R = 1;

// 接受cmd，并存储等待发送
void cmdCallback(const geometry_msgs::Vector3::ConstPtr &cmdMsg);

// 调试模型，记得改过来
bool debug = false;

// 使用案例
int main(int argc, char **argv)
{
    ros::init(argc, argv, "CAN");

    ros::NodeHandle n;
    int mode = 0;
    n.getParam("/mode", mode);
    ros::Subscriber subCmd = n.subscribe("/carCmd", 1, &cmdCallback);
    ros::Publisher pubVehicleInfo = n.advertise<geometry_msgs::Twist>("/current_vehicle_can_info", 1, true);

    // 初始化消息
    initRecvMessages();
    initSendMessages();

    // 打开CAN口
    CAN_InitConfig CanConfig;
    CanHandler CanIO(CAN_Device, 0, 1, CanConfig);
    DWORD opened;
    opened = CanIO.OpenDevice();

    // 打开第二个CHANNEL
    CAN_InitConfig config;

    if (CAN_ChannelStart(opened, 1, &config) != CAN_RESULT_OK)
    {
        ROS_ERROR_STREAM(" >>Init CAN1 error!");
        return 0;
    }
    else
    {
        // std::cout << "Init CAN11 success : " << opened << "," << 1 << std::endl;
        vcanstreamPtr.push_back(boost::shared_ptr<canstream>{new canstream(opened, 1)});
    }

    rtknavigation_Ptr prtknavigation = NULL;
    uwb_Ptr uwbPtr = NULL;

    // 获取这几个参数的地址， 用于后续控制发送什么消息
    send_args *send = &sendArg;
    // send_args *send50 = &sendArg50;
    recv_args *recv = &recvArg;
    recv->channel = 0; // 0 是channel 0,，默认为0

    // 设置发送进程的间隔， 单位是毫秒上升沿
    // 时间间隔为50ms
    send->interval = 50;

    // 进入自动驾驶模式
    CAN_Message *msg0x1801D071 = &all_can_send[0x1801D071];
    if (opened != 0)
    {
        // 第一次发送,发送5次
        send->num_frames = 2;
        send->data = new CAN_DataFrame[send->num_frames];
        send_all_safe(send);
        send->msg_arrived = true;
        ros::Rate r(50);

        for (int i = 0; i < 9; i++)
        {
            send_all_safe(send);
            r.sleep();
        }

        // 进入自动驾驶
        enterAutoDriving();
        // 进入转速模式
        controlModel();
        // 获取当前铰接角角度
        double angle = getSplice();
        //std::cout << "Initial Angle: " << angle << std::endl;

        // 初始化左转，右转阀门开度
        setLeftTurn(0);
        setRightTurn(0);
        
        setGear(global_cmd_D_R);

        for (int i = 0; i < 9; i++)
        {
            send_all_safe(send);
            r.sleep();
        }
    }

    ros::Rate loop_rate(100); // 休眠了两次，所以实际为50Hz

    while (ros::ok())
    {
        if (opened == 0)
        {
            ROS_ERROR("THE CAN IS NOT OPEN!!!");
            continue;
        }

        // 获取当前铰接角角度
        global_curAngle = getSplice();

        // 从底层读取速度并发布
        global_curSpd = getVel();

        printf("current speed: %lf\n", global_curSpd);
        printf("current angle: %lf\n", global_curAngle);
        
        printf("global_cmd_speed: %lf\n", global_cmd_spd);
        printf("global_cmd_angle: %lf\n", global_cmd_angle);

  
        setGear(global_cmd_D_R);

        setSpd(global_cmd_spd);

        setAngle(global_cmd_angle, global_curAngle, err_last, err_last_last, voltage);
        // setAngle(global_curSpd, global_curAngle, err_last, err_last_last, voltage);

        geometry_msgs::Twist msg;
        msg.linear.x = global_curSpd / 3.6;  // 底层车速单位km/h，所需速度单位m/s
        msg.angular.x = global_curAngle;

        pubVehicleInfo.publish(msg);
        loop_rate.sleep();

        send_all_safe(send);
        loop_rate.sleep();

        /*----------------------从rtk/uwb接受数据并发送----------------------*/
        for (size_t i = 0; i < vcanstreamPtr.size(); i++)
        {
            canstreamPtr canPtr = vcanstreamPtr[i];
            if (canPtr != NULL)
            {
                // ROS_INFO("can_io : %d , %d  \n", canPtr->dwDeviceHandle_, canPtr->can_id_);

                if ((canPtr->reclen_ = CAN_ChannelReceive(canPtr->dwDeviceHandle_, canPtr->can_id_, canPtr->rec_, 30, 10)) > 0)
                {
                    // ROS_INFO("%s receive msg num : %d \n", canPtr->sensor_name_.c_str(), canPtr->reclen_);
                    // 判断报文是rtk还是uwb
                    if (canPtr->data_in())
                    {
                        // rtk报文
                        if (canPtr->sensor_name_ == "rtknavigation")
                        {
                            if (!prtknavigation)
                            {
                                prtknavigation = boost::shared_ptr<rtknavigation>{new rtknavigation(n, canPtr)};
                                prtknavigation->publishrtk();
                            }
                            else
                                prtknavigation->publishrtk();
                        }

                        // uwb报文
                        if (canPtr->sensor_name_ == "uwb")
                        {
                            ROS_INFO("uwb报文   \n");
                            if (!uwbPtr)
                            {
                                uwbPtr = boost::shared_ptr<uwb>{new uwb(n, canPtr)};
                                uwbPtr->publishrtk();
                            }
                                uwbPtr->publishrtk();
                        }
                    }
                }
                else
                {
                    CAN_ErrorInformation err;
                    if (CAN_GetErrorInfo(canPtr->dwDeviceHandle_, canPtr->can_id_, &err) == CAN_RESULT_OK)
                    {
                        // LOG(INFO) << "Error !!!\n";
                    }
                    else
                    {
                        // LOG(INFO) << "no can msg received\n";
                    }
                }
                CAN_ClearReceiveBuffer(canPtr->dwDeviceHandle_, canPtr->can_id_);

            }
        }

        // canToHuman(CanIO.recv[0], CanIO.reclen);
        ros::spinOnce();
    }

    // 退出自动驾驶
    ROS_INFO("Exit autoDriving !!!");
    exitAutoDriving();

    send_all_safe(send);
    sleep(1);

    // if (!ros::ok())
    //     exit(0);

    delete[] send->data;
    send->run = false;
    recv->run = false;
    CanIO.join();
    return 0;
}

void cmdCallback(const geometry_msgs::Vector3::ConstPtr &cmdMsg)
{
    ROS_INFO("CMD Received From PID");
    // global_cmd_spd = (double)cmdMsg->x * 5 * 3.6;
    global_cmd_spd = 10.0;
    printf("************************");
    printf("control_cmd_speed: %lf\n", global_cmd_spd);
    printf("************************");
    global_cmd_angle = (double)cmdMsg->y;
    global_cmd_D_R = (int)cmdMsg->z;
}
