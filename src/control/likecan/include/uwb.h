#ifndef UWB_H
#define UWB_H
#include <cmath>

#include "canstream.h"
#include "ros/ros.h"

#include "location_msgs/RTK.h"

class uwb
{
public:
    uwb(ros::NodeHandle &nh, canstreamPtr canstream) : nh_(nh), canstream_(canstream)
    {   
        new_flag_ = -9999;
        publisher_ = nh_.advertise<location_msgs::RTK>("/Huace_rtk", 10);
    }

    void publishrtk();

private:
    double new_flag_;

    ros::NodeHandle &nh_;
    ros::Publisher publisher_;
    canstreamPtr canstream_;

    // 将location_msgs所有值设置为new_flag_
    void rtkdata_reset(location_msgs::RTK &rtkdata);

    double CAN_decode(const BYTE *raw_data, int lsb, int length, double ratio, double bias, int mode = 0);

    // 检查location_msgs是否填入
    bool rtkdata_isNew(const location_msgs::RTK &rtkdata);
};

typedef boost::shared_ptr<uwb> uwb_Ptr;

void uwb::publishrtk()
{
    location_msgs::RTK rtk;
    rtkdata_reset(rtk);
    double hours;
    double minutes;
    double seconds;

    for (auto frame = canstream_->vdata_.cbegin(); frame != canstream_->vdata_.cend(); frame++)
    {
        // const CAN_DataFrame &raw_data, int lsb, int length, double ratio, double bias, int mode = 0
        // raw_data, startByte_idx, length, ratio, bias);
        if (frame->uID == 0x503)
        {
            rtk.gpstime = CAN_decode(frame->arryData, 4, 32, 0, 1, 0);
            rtk.height  = CAN_decode(frame->arryData,  0, 32, -10000, 1e-3, 0);
        }

        if (frame->uID == 0x504)
        {
            rtk.latitude  = CAN_decode(frame->arryData, 4, 32, -180, 1e-7, 0);
            rtk.longitude = CAN_decode(frame->arryData,  0, 32, -180, 1e-7, 0);
        }

        if (frame->uID == 0x502)
        {
            rtk.heading = CAN_decode(frame->arryData, 4, 16, -360, 0.010986, 0);
            rtk.pitch   = CAN_decode(frame->arryData,  0, 16, -360, 0.010986, 0) ;
            rtk.roll    = CAN_decode(frame->arryData, 2, 16,  -360, 0.010986, 0);
        }
        
        if (frame->uID == 0x505)
        {
            double vel_x = CAN_decode(frame->arryData,  0, 16, -100, 0.0030517, 0);
            double vel_y = CAN_decode(frame->arryData, 2, 16,  -100,  0.0030517,0);
            rtk.velocity = sqrt(vel_x * vel_x + vel_y * vel_y);

        }

        // if (frame->uID == 0x500)
        // {
        //     rtk.AccelX = CAN_decode(frame->arryData,  0, 16,  -4, 0.0001220703125,0);
        //     rtk.AccelY = CAN_decode(frame->arryData, 2, 16, -4, 0.0001220703125,0);
        //     rtk.AccelZ = CAN_decode(frame->arryData, 4, 16,  -4,0.0001220703125, 0);
        // }

        if (rtkdata_isNew(rtk))
        {   
            ROS_INFO("%.3lf,%.8lf,%.8lf,%.3lf,%.2lf,%.2lf \n", rtk.gpstime,
                                                            rtk.longitude,
                                                            rtk.latitude,
                                                            rtk.height,
                                                            rtk.heading,
                                                            rtk.velocity);

            // ROS_INFO("%.4lf,%.4lf,%.4lf \n", rtk.AccelX,
            //                                 rtk.AccelY,
            //                                 rtk.AccelZ);
                                                            
            publisher_.publish(rtk);
            rtkdata_reset(rtk);
        }
    }
    canstream_->vdata_.clear();
}

void uwb::rtkdata_reset(location_msgs::RTK &rtkdata)
{
    rtkdata.gpstime = new_flag_;
    rtkdata.longitude = new_flag_;
    rtkdata.latitude = new_flag_;
    rtkdata.height = new_flag_;
    rtkdata.heading = new_flag_;
    rtkdata.roll = new_flag_;
    rtkdata.pitch = new_flag_;
    rtkdata.velocity = new_flag_;
}

bool uwb::rtkdata_isNew(const location_msgs::RTK &rtkdata)
{
    return (rtkdata.gpstime != new_flag_ &&
            rtkdata.latitude != new_flag_ &&
            rtkdata.longitude != new_flag_ &&
            rtkdata.height != new_flag_ &&
            rtkdata.heading != new_flag_ &&
            rtkdata.pitch != new_flag_ &&
            rtkdata.roll != new_flag_ &&
            rtkdata.velocity != new_flag_);
}

template <typename T>
T decodeMsg2(const BYTE *msg, int startByte_idx, int len, double offset, double factor)
{
    uint64_t temp = 0;
    const BYTE *startByte = msg + startByte_idx;
    int byteLength = len / 8;
    for (int i = 0; i < byteLength; i++)
    {
        int idx = byteLength - 1 - i;
        BYTE invd = (startByte[idx]);
        temp += (uint64_t(invd) << (8 * idx));
    }
    return T((temp * factor + offset));
}

double uwb::CAN_decode(const BYTE *raw_data, int startByte_idx, int length, double bias, double ratio, int mode)
{
    double output = decodeMsg2<double>(raw_data, startByte_idx, length,  bias, ratio);
    return output;
}

#endif