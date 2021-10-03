#ifndef DATA_H
#define DATA_H
#include <cmath>
#include <algorithm>
#include <string>
#include <unistd.h>
#include <fstream>
#include "Eigen/Dense"
#include "json.hpp"
#include <iostream>

namespace data_space
{

    using namespace std;

    using json = nlohmann::json;
    json ReadJson();
    extern json params_json;


    // 角度与弧度互相转化
    /**
     * @brief: 将弧度角限制在[0, 2*pi]内
     * @param: _rad: 弧度角
    **/
    static inline void NormalizeRad(double &rad)
    {
        if (rad < 0.0)
        {
            rad = rad - 2.0 * M_PI * (int)(rad / (2.0 * M_PI)) + 2.0 * M_PI;    //为什么是rad / (2.0 * M_PI)
        }
        rad = rad - 2.0 * M_PI * (int)(rad / (2.0 * M_PI));
        return;
    }

    /**
     * @brief: 弧度转角度
     * @param: _rad: 弧度角
    **/
    static inline void Rad2Deg(double &rad)
    {
        NormalizeRad(rad);
        rad *= (180.0 / M_PI);
        return;
    }

    /**
     * @brief: 角度转弧度
     * @param: _deg: 角度角
    **/
    static inline void Deg2Rad(double &deg)
    {
        deg *= (M_PI / 180.0);
        NormalizeRad(deg);
        return;
    }

    /**
     * @brief: 限幅
     * @param: n: 需要限幅的数值
     * @param: lower: 下界
     * @param: upper: 上界
    **/
    static inline double Clamp(double n, double lower, double upper)
    {
        return max(lower, min(n, upper));
    }

    /**
     * @brief: 求解两点间距离的平方
     * @param: x1, x2, y1, y2
     * @return: double: 两点间距离的平方
    **/
    static inline double PointDistanceSquare(double x1, double y1, double x2, double y2)
    {
        return sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

}


#endif