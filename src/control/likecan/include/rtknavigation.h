#ifndef RTKNAVIGATION_H
#define RTKNAVIGATION_H
#include <cmath>

#include "canstream.h"
#include "ros/ros.h"

#include "location_msgs/RTK.h"

class rtknavigation
{
public:
    rtknavigation(ros::NodeHandle &nh, canstreamPtr canstream) : nh_(nh), canstream_(canstream)
    {   
        new_flag_ = -100000;
        publisher_ = nh_.advertise<location_msgs::RTK>("/Huace_rtk", 10);
    }

    void publishrtk();

private:
    ros::NodeHandle &nh_;
    ros::Publisher publisher_;
    canstreamPtr canstream_;

    double new_flag_;
    void rtkdata_reset(location_msgs::RTK &rtkdata);
    double CAN_decode(const CAN_DataFrame &raw_data, int lsb, int length, double ratio, double bias, int mode);
    bool rtkdata_isNew(const location_msgs::RTK &rtkdata);
};

typedef boost::shared_ptr<rtknavigation> rtknavigation_Ptr;

void rtknavigation::publishrtk()
{
    location_msgs::RTK rtk;
    rtkdata_reset(rtk);
    double hours;
    double minutes;
    double seconds;

    for (auto frame = canstream_->vdata_.cbegin(); frame != canstream_->vdata_.cend(); frame++)
    {
        if (frame->uID == 0x320)
        {
            rtk.gpstime = CAN_decode(*frame, 40, 32, 0.001, 0, 0);
        }

        if (frame->uID == 0x323)
        {
            rtk.status = CAN_decode(*frame, 16, 8, 1, 0, 0);
        }

        if (frame->uID == 0x324)
        {
            rtk.latitude = CAN_decode(*frame, 24, 32, 1e-7, 0, 1);
            rtk.longitude = CAN_decode(*frame, 56, 32, 1e-7, 0, 1);
        }

        if (frame->uID == 0x325)
        {
            rtk.height = CAN_decode(*frame, 24, 32, 1e-3, 0, 1);
        }

        if (frame->uID == 0x32A)
        {
            rtk.heading = CAN_decode(*frame, 8, 16, 1e-2, 0, 0);
            rtk.pitch = CAN_decode(*frame, 24, 16, 1e-2, 0, 1);
            rtk.roll = CAN_decode(*frame, 40, 16, 1e-2, 0, 1);
        }
        
        if (frame->uID == 0x327)
            rtk.velocity = CAN_decode(*frame, 56, 16, 1e-2, 0, 1);


        if (rtkdata_isNew(rtk))
        {   
            ROS_INFO("%.3lf,%d,%.8lf,%.8lf,%.3lf,%.2lf,%.2lf \n", rtk.gpstime,
                                                            rtk.status,
                                                            rtk.longitude,
                                                            rtk.latitude,
                                                            rtk.height,
                                                            rtk.heading,
                                                            rtk.velocity);
                                                            
            publisher_.publish(rtk);
            rtkdata_reset(rtk);
        }
    }
    canstream_->vdata_.clear();
}

void rtknavigation::rtkdata_reset(location_msgs::RTK &rtkdata)
{
    rtkdata.gpstime = new_flag_;
    rtkdata.status = 99;
    rtkdata.longitude = new_flag_;
    rtkdata.latitude = new_flag_;
    rtkdata.height = new_flag_;
    rtkdata.heading = new_flag_;
    rtkdata.roll = new_flag_;
    rtkdata.pitch = new_flag_;
    rtkdata.velocity = new_flag_;
}

bool rtknavigation::rtkdata_isNew(const location_msgs::RTK &rtkdata)
{
    return (rtkdata.gpstime != new_flag_ &&
            rtkdata.status != 99 &&
            rtkdata.latitude != new_flag_ &&
            rtkdata.longitude != new_flag_ &&
            rtkdata.height != new_flag_ &&
            rtkdata.heading != new_flag_ &&
            rtkdata.pitch != new_flag_ &&
            rtkdata.roll != new_flag_ &&
            rtkdata.velocity != new_flag_);
}

double rtknavigation::CAN_decode(const CAN_DataFrame &raw_data, int lsb, int length, double ratio, double bias, int mode = 0)
{
    int lsb_byte = lsb / 8;
    int lsb_bit = lsb % 8;
    int msb_bit = (lsb_bit + length - 1) % 8;

    int num_byte;
    if ((lsb_bit + length - 1) / 8 == 0)
        num_byte = 1;
    else
        num_byte = 1 + 1 + (length - (8 - lsb_bit) - (msb_bit + 1)) / 8;
    int msb_byte = lsb_byte - num_byte + 1;
    // printf("num_byte : %d ,lsb_byte : %d, lsb_bit : %d, msb_bit : %d \n",num_byte, lsb_byte, lsb_bit, msb_bit);
    int deviation = 0;
    int data = 0;

    if (num_byte == 1)
    {
        int tmp = 0;
        for (int i = lsb_bit; i <= msb_bit; i++)
            tmp += (int)pow(2, i);
        data += (int)((raw_data.arryData[lsb_byte] & tmp) >> lsb_bit);
        data = ratio * data + bias;
        return data;
    }

    for (int byte = lsb_byte; byte > lsb_byte - num_byte; byte--)
    {
        // printf("calculate byte %d : %lf \n", byte, data);
        if (byte == lsb_byte)
        {
            int tmp = 0;
            for (int i = lsb_bit; i <= 7; i++)
                tmp += round(pow(2, i));
            data += (int)((raw_data.arryData[byte] & tmp) >> lsb_bit);
            deviation += (8 - lsb_bit);
        }
        else if (byte == lsb_byte - num_byte + 1)
        {
            int tmp = 0;
            for (int i = 0; i <= msb_bit; i++)
                tmp += round(pow(2, i));
            data += (int)((raw_data.arryData[byte] & tmp) << deviation);
        }
        else
        {
            data += (int)((raw_data.arryData[byte]) << deviation);
            deviation += 8;
        }
        // printf("calculate byte %d : %lf \n", byte, data);
    }

    if (mode == 1)
    {
        int tmp = round(pow(2, msb_bit));
        if ((raw_data.arryData[msb_byte] & tmp) == tmp)
        {
            data = (-1) * (pow(2, length) - data - 1);
        }
    }

    double output = ratio * data + bias;
    return output;
}
#endif