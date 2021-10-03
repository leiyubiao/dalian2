#ifndef CanHandler_H
#define CanHandler_H

#include <thread>
#include <mutex>
#include "ICANCmd.h"
#include <glog/logging.h>
#include <cmath>

// CanProcess命名空间， 使用 using namespace CanProcess; 或者 CanProcess::something
namespace CanProcess
{
    // 接受线程的参数， run默认值必须为 true， 否则将立即退出接受线程
    struct recv_args
    {
        bool run = true;
        DWORD channel = 0;
    };
    extern recv_args recvArg;

    // 发送线程的参数， run同理
    struct send_args
    {
        bool run = true;
        std::mutex datalock; //
        CAN_DataFrame *data = nullptr;
        DWORD sndType = 2;
        DWORD channel = 0;
        bool msg_arrived = false;
        int num_frames = 4;
        int interval = 20;
    };

    //  sendArg50 是间隔为50ms的线程， sendArg对应间隔为20ms的线程
    extern send_args sendArg;
    // extern send_args sendArg50;

    // 用于测试的线程锁
    extern std::mutex testLock;
    extern int test;

    class CanHandler
    {
    public:
        /**
         * Create a CAN processor
        */
        CanHandler();

        /**
         * Create a CAN processor
         * @param DevType 设备类型
         * @param Idex USB索引， 从0开始
         * @param Channel 对应CAN卡上的CAN通道， 1代表 CAN0， 2代表 CAN1， 3代表CAN0和CAN1
         * @param config CAN卡的设定， 具体参考CanHandler.h 
        */
        CanHandler(int DevType, int Idex, int Channel, CAN_InitConfig config);

        /**
         * 析构函数， 关闭Can通道
        */
        ~CanHandler()
        {
            if ((DeviceChannel & 1) == 1)
            {
                printf("CAN_ChannelStop 0\r\n");
                CAN_ChannelStop(DeviceHandle, 0);
            }

            if ((DeviceChannel & 2) == 2)
            {
                printf("CAN_ChannelStop 1\r\n");
                CAN_ChannelStop(DeviceHandle, 1);
            }

            CAN_DeviceClose(DeviceHandle);
        }

        /**
         * 开启CAN卡设备， 并激活相应的通道 （参数是构造函数确定的）
        */
        bool OpenDevice()
        {
            DeviceHandle = CAN_DeviceOpen(DeviceType, DeviceIdx, 0);
            if (!DeviceHandle)
                printf("Open Device Error \n");
            else
                printf("Device Opened \n");

            if ((DeviceChannel & 1) == 1)
            {
                Can_Config.dwBtr[0] = 0x01;
                if (CAN_ChannelStart(DeviceHandle, 0, &Can_Config) != CAN_RESULT_OK)
                    printf("Start CAN 0 ERROR \n");
                else
                    printf("CAN 0 Started \n");
            }

            if ((DeviceChannel & 2) == 2)
            {
                Can_Config.dwBtr[0] = 0x00;
                if (CAN_ChannelStart(DeviceHandle, 1, &Can_Config) != CAN_RESULT_OK)
                    printf("Start CAN 1 ERROR \n");
                else
                    printf("CAN 1 Started \n");
            }

            if (CAN_GetDeviceInfo(DeviceHandle, &DevInfo) != CAN_RESULT_OK)
            {
                printf("GetDeviceInfo error \n");
            }
            sleep(5);
            return DeviceHandle;
        }

        /**
         * 接受数据的线程
         * @arg 接受数据的参数
        */
        void recvLoop(recv_args *arg);

        /**
         * 发送数据的线程，
        */
        void sendLoop(send_args *arg);

        /**
         * 等待发送和接受结束， 作用类似于 ros::Spin();
        */
        void join()
        {
            recvThread.join();
            sendThread.join();
            // sendThread50.join();
        }

    private:
        // 线程们
        std::thread recvThread;
        std::thread sendThread;
        // std::thread sendThread50;

    public:
        // 接收到的数据
        std::mutex recv_data_lock;
        CAN_DataFrame recv[2][100];
        int reclen = 0;

    private:
        DWORD DeviceHandle = 0;
        DWORD DeviceType = USBCAN_E_1CH;
        DWORD DeviceIdx = 1;
        DWORD DeviceChannel = 1;

        CAN_InitConfig Can_Config;

        CAN_DeviceInformation DevInfo;

        // testCan程序中遗留的参数，似乎没什么用
        DWORD CanSendType;
        DWORD CanSendFrames;
        DWORD CanSendTimes;
        DWORD CanSendDelay;
    };

    /**
     * Encode & decode
     * 下面解析代码为intel的，传入的参数 @param lsb @param length @param factor @param offset与 excel表中的消息属性对应
    */

    /**
     * Encode data to can message
     * @param data 可以选择不同类型的数据， 例如 bool int double 等等
     * @param lsb @param length @param factor @param offset 与 excel表中的消息属性对应
    */
    template <typename T> // 模板函数必须定义在头文件中， 否则无法链接
    void encodeMsg(T data, int lsb, int length, double factor, double offset, BYTE *output)
    {
        data = (data - offset) / factor;
        // 确定起始的字节位置，也就是layout表上，消息开始的行数（不是bit位置）;intel的起始lsb在高位字节
        // output是一个字节数组，lsb/8整型在这里做索引
        // 确定起始字节行
        BYTE *startByte = lsb / 8 + output;

        // lsb的byte和bit位
        int lsb_byte = lsb / 8;
        int lsb_bit = lsb % 8;

        // msb的bit位
        int msb_bit = (lsb_bit + length - 1) % 8;
        int num_byte;

        // 判断lsb和msb是否在同一字节行
        if ((lsb_bit + length - 1) / 8 == 0)
            num_byte = 1;
        // lsb和msb不在同一字节行，求解lsb和msb所差字节行
        else
            num_byte = 1 + 1 + (length - (8 - lsb_bit) - (msb_bit + 1)) / 8;

        // 确定msb的byte行，intel的msb_byte在lsb_byte下
        int msb_byte = lsb_byte + num_byte - 1;
        // printf("num_byte : %d ,lsb_byte : %d, lsb_bit : %d, msb_bit : %d \n",num_byte, lsb_byte, lsb_bit, msb_bit);

        // 把raw_data转成8字节数据
        uint64_t temp(data);

        // 截断该数据， 防止数据溢出
        uint64_t i = (1 << length) - 1;
        temp &= i;

        // 把数据转化的二进制移到lsb位置
        temp <<= (lsb % 8);

        for (int i = num_byte - 1; i >= 0; i--)
        {
            int idx = num_byte - 1 - i;
            startByte[idx] |= ((temp >> (8 * (idx))) & (255));
        }
    }

    /**
     * Decode can message to data, 上面全部反向操作就行了
     * @param raw_data 可以选择不同类型的数据， 例如 bool int double 等等
     * @param lsb  @param length @param offset @param factor @param mode 与excel表中的消息属性对应
    */
    template <typename T>
    T decodeMsg(BYTE *raw_data, int lsb, int length, double factor, double offset, int mode = 0)
    {
        // lsb的byte和bit位
        int lsb_byte = lsb / 8;
        int lsb_bit = lsb % 8;
        // msb的bit位
        int msb_bit = (lsb_bit + length - 1) % 8;

        int num_byte;
        // 判断lsb和msb是否在同一字节行
        if ((lsb_bit + length - 1) / 8 == 0)
            num_byte = 1;
        // lsb和msb不在同一字节行，求解lsb和msb所差字节行
        else
            num_byte = 1 + 1 + (length - (8 - lsb_bit) - (msb_bit + 1)) / 8;

        // 确定msb的byte行，intel的msb_byte在lsb_byte下
        int msb_byte = lsb_byte + num_byte - 1;
        // printf("num_byte : %d ,lsb_byte : %d, lsb_bit : %d, msb_bit : %d \n",num_byte, lsb_byte, lsb_bit, msb_bit);
        int deviation = 0;
        int data = 0;

        // 当lsb和 msb在同一字节行，不需要移位操作
        if (num_byte == 1)
        {
            int tmp = 0;
            for (int i = lsb_bit; i <= msb_bit; i++)
                tmp += (int)pow(2, i);
            data += (int)((raw_data[lsb_byte] & tmp) >> lsb_bit);
	if (mode == 1)
        {
            int tmp_ = round(pow(2, msb_bit));
	    // printf("\n msb_bit: %d\n", (raw_data[msb_byte] & tmp_));
            if ((raw_data[msb_byte] & tmp_) == tmp_)
            {
                data = (-1) * (pow(2, length) - data - 1);
            }
        }
            double output = factor * data + offset;
            return T(output);
        }

        // 当lsb和msb不在同一行，需要移位操作
        // 当数据处在 两个byte行时，需要移位拼接
        for (int byte = lsb_byte; byte < lsb_byte + num_byte; byte++)
        {
            // printf("calculate byte %d : %lf \n", byte, data);
            if (byte == lsb_byte)
            {
                int tmp = 0;
                for (int i = lsb_bit; i <= 7; i++)
                    tmp += round(pow(2, i));
                // lsb需要向右移位lsb_bit
                data += (int)((raw_data[byte] & tmp) >> lsb_bit);
                deviation += (8 - lsb_bit);
            }

            else if (byte == lsb_byte + num_byte - 1)
            {
                int tmp = 0;
                for (int i = 0; i <= msb_bit; i++)
                    tmp += round(pow(2, i));
                data += (int)((raw_data[byte] & tmp) << deviation);
            }

            else
            {
                data += (int)((raw_data[byte]) << deviation);
                deviation += 8;
            }
            // printf("calculate byte %d : %lf \n", byte, data);
        }

        // 如果can 报文给的是反码
        if (mode == 1)
        {
            int tmp = round(pow(2, msb_bit));
	    // printf("\n msb_bit: %d\n", (raw_data[msb_byte] & tmp));
            if ((raw_data[msb_byte] & tmp) == tmp)
            {
                data = (-1) * (pow(2, length) - data - 1);
            }
        }

        double output = factor * data + offset;
        return T(output);
    }

    /**
     * Encode & decode
     * 下面解析代码为motorola的，传入的参数 @param lsb @param length @param factor @param offset与 excel表中的消息属性对应
    */

}

#endif
