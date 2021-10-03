#ifndef CANSTREAM_H
#define CANSTREAM_H

#include <iostream>
#include <string>
#include <deque>

#include "boost/shared_ptr.hpp"
#include "ICANCmd.h"

class canstream
{
public:
    canstream(DWORD dwDeviceHandle = 0, int can_id = 0) : dwDeviceHandle_(dwDeviceHandle), can_id_(can_id)
    {
        init_ = 0;
    }
    std::string sensor_name_;
    std::deque<CAN_DataFrame> vdata_;
    bool init_;

public:
    bool data_in();
    DWORD dwDeviceHandle_;
    int can_id_;

    int reclen_ = 0;
    CAN_DataFrame rec_[30]; // kongjian
};

typedef boost::shared_ptr<canstream> canstreamPtr;

bool canstream::data_in()
{
    for (int i = 0; i < reclen_; i++)
    {
        
        vdata_.push_back(rec_[i]);

        if (!init_)
        {   
            // debug
            printf("receive uID : %04X \n", rec_[i].uID);

            if (rec_[i].uID == 0x540)
            {
                sensor_name_ = "esr";
                init_ = true;
            }
            // else if (rec_[i].uID == 0x300)
            // {
            //     sensor_name_ = "lux4";
            //     init_ = true;
            // }
            else if (rec_[i].uID == 0x766)
            {
                sensor_name_ = "mobileye";
                init_ = true;
            }
            else if (rec_[i].uID == 0x320)
            {
                sensor_name_ = "rtknavigation";           // 大陆跟荣威的惯导冲突了
                init_ = true;
            }
            else if (rec_[i].uID == 0x101)
            {
                sensor_name_ = "control_wire";
                init_ = true;
            }
            else if (rec_[i].uID == 0x500)
            {
                sensor_name_ = "uwb";
                init_ = true;
            }
            else
            {
                init_ = false;
            }
        }
    }

    if (!init_)
        vdata_.clear();

    return init_;
}

#endif