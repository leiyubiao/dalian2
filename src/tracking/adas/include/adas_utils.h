#ifndef ADAS_UTILS_H
#define ADAS_UTILS_H
#include <iostream>
#include <vector>
#include <cmath>
#include "data.h"
#include <ros/ros.h>

// 自然参数
#define R0 6378137.0
// #define e 0.0818191908425
const double e = 0.0818191908425;
const double torad = M_PI / 180;

// 运行频率
#define FRE 100
// /route_data.bin
// 地图路径
// TODO: 采集的轨迹保存的路径
#define DATA_PATH "/home/leiyubiao/dalian/src/tracking/adas/map"
#define DATA_NAME_REAL_ROUTE "/route_data.bin"

// 地图点数据格式
struct PositionConf
{
    double gpstime;
    double x;                //单位: m
    double y;                //单位: m
    double z;
    double longitude;
    double latitude;
    double height;
    double heading;          //单位: rad
    double pitch;
    double roll;
    double velocity;         //单位: m/s
    double dist;
};


// PID格式
struct PIDConf
{
  double kp;
  double ki;
  double kd;
  double kaw;
  double integrator_saturation_level;
  double output_saturation_level;
  bool integrator_enabled;
};

/**
 * @brief: 地图点的拷贝
 * @param: p1: 采集的地图点
 * @param: p2: 拷贝点
 **/
void positionConf_copy(const PositionConf &p1, PositionConf &p2);


/**
 * @brief: 坐标变换，将点从ECEF转到ENU
 * @param: p: 轨迹点
 * @param: longitude, latitude, height: 原点的经纬度
 **/
void gps2xy(PositionConf &p, const double &longitude, const double &latitude, const double &height);


// 惯导坐标系->车辆中心坐标系
/**
 * @brief: 惯导坐标系转到以车辆中心为原点的坐标系下
 * @param: p: 轨迹点
 * @param: insgps_x, insgps_y: 车辆中心点在gps位置点
 **/
void insgps2center(PositionConf &p, const double insgps_x, const double insgps_y);

#endif
