#include "CanMsgDefs.h"
#include "map"

namespace CanProcess
{
    std::map<DWORD, CAN_Message> all_can_send;
    std::map<DWORD, CAN_Message> all_can_recv;

    void initSendMessages()
    {
        //DWORD ids[3] = {0x318, 0x319, 0x31A};
        DWORD ids[2] = {0x1801D071, 0x1802D071};
        for (auto i : ids)
        {
            all_can_send[i] = CAN_Message(i);
        }

        CAN_Message *msg0x1801D071 = &all_can_send[0x1801D071];
        msg0x1801D071->all_bool_data["Req_DrivingMode"] = SingleMsg_bool("Req_DrivingMode", 0, 1, 1, 0); //请求车辆驾驶模式
        msg0x1801D071->all_bool_data["Req_SteerWheel"] = SingleMsg_bool("Req_SteerWheel", 1, 1, 1, 0);   //自动驾驶转向控制使能
        msg0x1801D071->all_bool_data["Req_Throttle"] = SingleMsg_bool("Req_Throttle", 2, 1, 1, 0);       //自动驾驶油门控制使能
        msg0x1801D071->all_bool_data["Req_Brake"] = SingleMsg_bool("Req_Brake", 3, 1, 1, 0);             //自动驾驶制动控制使能
        msg0x1801D071->all_int_data["Req_AutoDriveEnState"] = SingleMsg_int("Req_AutoDriveEnState", 4, 2, 1, 0);
        msg0x1801D071->all_int_data["Req_Gear"] = SingleMsg_int("Req_Gear", 6, 2, 1, 0);                                //请求目标档位
        msg0x1801D071->all_double_data["Req_LeftValve"] = SingleMsg_double("Req_LeftValve", 8, 16, 0.0015259022, 0);    //请求左转阀口开度
        msg0x1801D071->all_double_data["Req_RightValve"] = SingleMsg_double("Req_RightValve", 24, 16, 0.0015259022, 0); //请求右转阀口开度
        msg0x1801D071->all_double_data["Req_SpinSpeed"] = SingleMsg_double("Req_SpinSpeed", 40, 16, 0.0015259022, 0);   //请求转速百分比
        msg0x1801D071->all_int_data["Count_1"] = SingleMsg_int("Count_1", 56, 8, 1, 0);  //计数器

        
        CAN_Message *msg0x1802D071 = &all_can_send[0x1802D071];
        msg0x1802D071->all_double_data["Req_BrakeRate"] = SingleMsg_double("Req_BrakeRate", 0, 16, 0.0015259022, 0); //请求目标制动踏板开度
        msg0x1802D071->all_bool_data["Req_AutoHandBrake"] = SingleMsg_bool("Req_AutoHandBrake", 16, 1, 1, 0);        //请求自动手刹
        msg0x1802D071->all_int_data["Req_CleanMode"] = SingleMsg_int("Req_CleanMode", 17, 2, 1, 0);                  //请求目标清扫模式
        msg0x1802D071->all_int_data["Req_SetSweep"] = SingleMsg_int("Req_SetSweep", 19, 3, 1, 0);                    //请求调节扫盘动作
        msg0x1802D071->all_int_data["Req_TrashBin"] = SingleMsg_int("Req_TrashBin", 22, 2, 1, 0);                    //请求垃圾仓动作
        msg0x1802D071->all_bool_data["Req_LeftLight"] = SingleMsg_bool("Req_LeftLight", 24, 1, 1, 0);                //请求左转灯
        msg0x1802D071->all_bool_data["Req_RightLight"] = SingleMsg_bool("Req_RightLight", 25, 1, 1, 0);              //请求右转灯
        msg0x1802D071->all_bool_data["Req_BigLight"] = SingleMsg_bool("Req_BigLight", 26, 1, 1, 0);                  //请求大灯
        msg0x1802D071->all_bool_data["Req_WarningLight"] = SingleMsg_bool("Req_WarningLight", 27, 1, 1, 0);          //请求警示灯
        msg0x1802D071->all_bool_data["Req_Horn"] = SingleMsg_bool("Req_Horn", 28, 1, 1, 0);                          //请求喇叭
        msg0x1802D071->all_bool_data["Req_SmallLight"] = SingleMsg_bool("Req_SmallLight", 29, 1, 1, 0);              //请求小灯
        msg0x1802D071->all_int_data["Req_Wiper"] = SingleMsg_int("Req_Wiper", 30, 2, 1, 0);                          //请求雨刮
        msg0x1802D071->all_int_data["Count_2"] = SingleMsg_int("Count_2", 56, 8, 1, 0);//计数器

    }

    void initRecvMessages()
    {
        DWORD ids[2] = {0x180171D0, 0x180271D0};
        for (auto i : ids)
        {
            all_can_recv[i] = CAN_Message(i);
        }

        // all message in message 0x180171D0
        CAN_Message *msg0x180171D0 = &all_can_recv[0x180171D0];
        msg0x180171D0->all_int_data["DrivingMode"] = SingleMsg_int("DrivingMode", 1, 2, 1, 0, 0);             //驱动模式
        msg0x180171D0->all_bool_data["AutoDriveEnState"] = SingleMsg_bool("AutoDriveEnState", 3, 1, 1, 0, 0); //控制模式
        msg0x180171D0->all_int_data["Real_Gear"] = SingleMsg_int("Real_Gear", 4, 2, 1, 0, 0);                 //当前档位
        msg0x180171D0->all_bool_data["Real_HandBrake"] = SingleMsg_bool("Real_HandBrake", 6, 1, 1, 0, 0);     //手刹状态

        msg0x180171D0->all_bool_data["Real_LeftLight"] = SingleMsg_bool("Real_LeftLight", 8, 1, 1, 0, 0);        //左转灯状态
        msg0x180171D0->all_bool_data["Real_RightLight"] = SingleMsg_bool("Real_RightLight", 9, 1, 1, 0, 0);      //右转灯状态
        msg0x180171D0->all_bool_data["Real_BigLight"] = SingleMsg_bool("Real_BigLight", 10, 1, 1, 0, 0);         //大灯状态
        msg0x180171D0->all_bool_data["Real_WarningLight"] = SingleMsg_bool("Real_WarningLight", 11, 1, 1, 0, 0); //警示灯状态
        msg0x180171D0->all_bool_data["Real_Horn"] = SingleMsg_bool("Real_Horn", 12, 1, 1, 0, 0);                 //喇叭状态
        msg0x180171D0->all_bool_data["Real_SmallLight"] = SingleMsg_bool("Real_SmallLight", 13, 1, 1, 0, 0);     //小灯状态
        msg0x180171D0->all_int_data["Real_Wiper"] = SingleMsg_int("Real_Wiper", 14, 2, 1, 0, 0);                 //雨刮状态

        msg0x180171D0->all_int_data["Real_CleanMode"] = SingleMsg_int("Real_CleanMode", 16, 2, 1, 0, 0);         //当前清扫模式
        msg0x180171D0->all_int_data["Real_Sweep"] = SingleMsg_int("Real_Sweep", 18, 3, 1, 0, 0);                 //扫盘动作状态
        msg0x180171D0->all_bool_data["Real_TrashBinMode"] = SingleMsg_bool("Real_TrashBinMode", 21, 1, 1, 0, 0); //垃圾仓及后门状态
        msg0x180171D0->all_int_data["Real_TrashBin"] = SingleMsg_int("Real_TrashBin", 22, 2, 1, 0, 0);           //垃圾仓动作状态

        // all message in message 0x180271D0
        CAN_Message *msg0x180271D0 = &all_can_recv[0x180271D0];
        msg0x180271D0->all_double_data["Real_BrakeRate"] = SingleMsg_double("Real_BrakeRate", 0, 16, 0.0015259022, 0, 0);     //实际制动开度
        msg0x180271D0->all_double_data["Real_SpliceAngle"] = SingleMsg_double("Real_SpliceAngle", 16, 16, 0.001373333, 0, 1); //铰接角
        msg0x180271D0->all_double_data["Real_Speed"] = SingleMsg_double("Real_Speed", 32, 8, 0.1, 0, 1);                     //车速
    }

    /*
    * 底层传过来的message解码为十进制数据
    **/
    void canToHuman(CAN_DataFrame *df, int length)
    {
        for (int i = 0; i < length; i++)
        {
            // printf("CAN ID: %x\n", df[i].uID);
            // LOG(INFO) << "CAN ID:" << df[i].uID << "\n";
            if (all_can_recv.find(df[i].uID) == all_can_recv.end())
                continue;

            CAN_Message *temp = &all_can_recv[df[i].uID];
            for (auto &msg_pair : temp->all_bool_data)
            {
                auto &msg = msg_pair.second;
                msg.data = decodeMsg<bool>(df[i].arryData, msg.lsb, msg.length, msg.factor, msg.offset, msg.mode);
            }

            for (auto &msg_pair : temp->all_int_data)
            {
                auto &msg = msg_pair.second;
                msg.data = decodeMsg<int>(df[i].arryData, msg.lsb, msg.length, msg.factor, msg.offset, msg.mode);
            }

            for (auto &msg_pair : temp->all_double_data)
            {
                auto &msg = msg_pair.second;
                msg.data = decodeMsg<double>(df[i].arryData, msg.lsb, msg.length, msg.factor, msg.offset, msg.mode);
            }
        }
    }

    void CAN_Message::toDataFrame(CAN_DataFrame *dataframe)
    {
        if (!dataframe)
            return;
        // 扩展帧
        dataframe->bExternFlag = 1;
        dataframe->uID = id;

        for (int i = 0; i < 8; i++)
        {
            dataframe->arryData[i] = 0;
        }
        for (auto &msg_pair : all_double_data)
        {
            auto &msg = msg_pair.second;
            // LOG(INFO) << "double message encoded: " << msg.data;
            encodeMsg<double>(msg.data, msg.lsb, msg.length, msg.factor, msg.offset, dataframe->arryData);
        }

        for (auto &msg_pair : this->all_int_data)
        {
            auto &msg = msg_pair.second;
            // LOG(INFO) << "int message encoded: " << msg.data;
            encodeMsg<int>(msg.data, msg.lsb, msg.length, msg.factor, msg.offset, dataframe->arryData);
        }

        for (auto &msg_pair : this->all_bool_data)
        {
            auto &msg = msg_pair.second;
            // LOG(INFO) << "bool message encoded: " << msg.data;
            encodeMsg<bool>(msg.data, msg.lsb, msg.length, msg.factor, msg.offset, dataframe->arryData);
        }
    }

}
