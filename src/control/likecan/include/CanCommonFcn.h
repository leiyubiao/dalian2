#ifndef CANCOMMONFCN_H
#define CANCOMMONFCN_H

#include "CanMsgDefs.h"

// 这里按照说明书定义了一些常用函数， 可以自行添加，
// 注意这些函数只修改了预存的数据，
// 并没有修改发送的数据
namespace CanProcess
{
    // 先发送帧消息的ID
    void send_by_id(DWORD id, CAN_DataFrame *data)
    {
        if (all_can_send.find(id) != all_can_send.end())
        {
            all_can_send[id].toDataFrame(data);
        }
    }

    // 发送每帧消息的64bit数据，该数据存在CAN_DataFrame *data里
    void send_all(CAN_DataFrame *data)
    {
        int i = 0;
        for (auto &msg_pair : all_can_send)
        {
            auto &msg = msg_pair.second;
            msg.toDataFrame(data + i);
            i++;
        }
    }

    void send_all_safe(send_args *send)
    {
        if (send)
        {
            std::unique_lock<std::mutex> lock(send->datalock);
            send_all(send->data);
            // 添加计数器
            int counter_1 = all_can_send[0x1801D071].all_int_data["Count_1"].data + 1;
            int counter_2 = all_can_send[0x1802D071].all_int_data["Count_2"].data + 1;
            all_can_send[0x1801D071].all_int_data["Count_1"].data = counter_1 > 255 ? 0 : counter_1;
            all_can_send[0x1802D071].all_int_data["Count_2"].data = counter_2 > 255 ? 0 : counter_2;
            // printf("counter_1: %d\n", all_can_send[0x1801D071].all_int_data["Count_1"].data );
            // printf("counter_2: %d\n", all_can_send[0x1801D071].all_int_data["Count_1"].data );
        }
        
    }

    /**
     * 发送目标转角，发送给EPS，左转
    */
    void setLeftTurn(double angle)
    {
        all_can_send[0x1801D071].all_double_data["Req_LeftValve"].data = angle;         
    }

    /**
     * 发送目标转角，发送给EPS，右转
    */
    void setRightTurn(double angle)
    {
        all_can_send[0x1801D071].all_double_data["Req_RightValve"].data = angle;     
    }

    /**
     * 进入自动驾驶模式
    */
    void enterAutoDriving()
    {
        all_can_send[0x1801D071].all_bool_data["Req_DrivingMode"].data = 1;
        all_can_send[0x1801D071].all_bool_data["Req_SteerWheel"].data = 1;
        all_can_send[0x1801D071].all_bool_data["Req_Throttle"].data = 1;
        all_can_send[0x1801D071].all_bool_data["Req_Brake"].data = 1;
    }

    /**
     * 退出自动驾驶模式
    */
    void exitAutoDriving()
    {
        all_can_send[0x1801D071].all_bool_data["Req_DrivingMode"].data = 0;
        all_can_send[0x1801D071].all_bool_data["Req_SteerWheel"].data = 0;
        all_can_send[0x1801D071].all_bool_data["Req_Throttle"].data = 0;
        all_can_send[0x1801D071].all_bool_data["Req_Brake"].data = 0;
    }

    /**
     * 设置为转速模型
    */
    void controlModel()
    {
        all_can_send[0x1801D071].all_int_data["Req_AutoDriveEnState"].data = 1;
    }

    /**
     * 换挡控制
    */
    void setGear(int tarGear)
    {
        all_can_send[0x1801D071].all_int_data["Req_Gear"].data = tarGear;
    }

    /**
     * 速度控制，下发转速百分比
    */
    void setSpd(double tarSpd)
    {
        all_can_send[0x1801D071].all_double_data["Req_SpinSpeed"].data = tarSpd;
    }
   

    /**
     * 接受反馈量
     * 反馈量包括车速，铰接角
    */

    double getVel()
    {     
        return all_can_recv[0x180271D0].all_double_data["Real_Speed"].data;
    }


    /**
     * 获取铰接角转角
    */
    double getSplice()
    {
        return all_can_recv[0x180271D0].all_double_data["Real_SpliceAngle"].data;
    }

    double getBrake()
    {
	return all_can_recv[0x180271D0].all_double_data["Real_BrakeRate"].data;
    }
    double setBrake(double rate)
    {
    return all_can_send[0x1802D071].all_double_data["Req_BrakeRate"].data;
    }

    /*转角PID控制*/
    void setAngle(double target, double current, double &err_last, double &err_last_last, double &voltage)
    {
	double Kp = 4.3;
	double Ki = 0.0;
	double Kd = 0.4; //定义比例、积分、微分系数
	double err = target - current;
        double increment = Kp * (err - err_last) + Ki * err + Kd * (err - 2 * err_last + err_last_last);
        //printf("increment: %lf", increment);
        voltage += increment;
        
        // setSpd(5);
        if (voltage > 0)
        {
            // if (voltage < 3.0 && voltage > 0.6) voltage = 3.5;
            // else if (voltage <= 0.6) voltage = 0.0;
            if (voltage > 100) voltage = 99.0;
            //printf("voltage: %lf", voltage);
            setRightTurn(voltage);
            setLeftTurn(0.0);
        }
        else
        {
            // if (voltage > -3.0 && voltage < -0.6) voltage = -3.5;
            // else if (voltage >= -0.6) voltage = 0.0;
            if (voltage < -100) voltage = -99.0;
            //printf("voltage: %lf", voltage);
            setRightTurn(0.0);
            setLeftTurn(-voltage);
        }
        err_last = err;
        err_last_last = err_last;
    }
}
#endif
