#include "adas_utils.h"

// 地图点的拷贝 p2 = p1
void positionConf_copy(const PositionConf &p1, PositionConf &p2)
{
    p2.gpstime = p1.gpstime;
    p2.x = p1.x;
    p2.y = p1.y;
    p2.z = p1.z;
    p2.longitude = p1.longitude;
    p2.latitude = p1.latitude;
    p2.height = p1.height;
    p2.heading = p1.heading;
    p2.pitch = p1.pitch;
    p2.roll = p1.roll;
    p2.velocity = p1.velocity;
    p2.dist = p1.dist;
}

// 坐标变换函数
// 点,原点经纬度
void gps2xy(PositionConf &p, const double &longitude, const double &latitude, const double &height)
{
    double Re = R0 / sqrt(1 - e * e * sin(latitude * torad) * sin(latitude * torad));
    double x0_ECEF = (Re + height) * cos(latitude * torad) * cos(longitude * torad);
    double y0_ECEF = (Re + height) * cos(latitude * torad) * sin(longitude * torad);
    double z0_ECEF = (Re * (1 - e * e) + height) * sin(latitude * torad);

    Re = R0 / sqrt(1 - e * e * sin(p.latitude * torad) * sin(p.latitude * torad));
    double dx_ECEF = (Re + p.height) * cos(p.latitude * torad) * cos(p.longitude * torad) - x0_ECEF;
    double dy_ECEF = (Re + p.height) * cos(p.latitude * torad) * sin(p.longitude * torad) - y0_ECEF;
    double dz_ECEF = (Re * (1 - e * e) + p.height) * sin(p.latitude * torad) - z0_ECEF;

    // ECEF to ENU
    p.x = -sin(p.longitude * torad) * dx_ECEF + cos(p.longitude * torad) * dy_ECEF;
    p.y = -sin(p.latitude * torad) * cos(p.longitude * torad) * dx_ECEF - sin(p.latitude * torad) * sin(p.longitude * torad) * dy_ECEF + cos(p.latitude * torad) * dz_ECEF;
    p.z = cos(p.latitude * torad) * cos(p.longitude * torad) * dx_ECEF + cos(p.latitude * torad) * sin(p.longitude * torad) * dy_ECEF + sin(p.latitude * torad) * dz_ECEF;
}

// 惯导坐标系->车辆中心坐标系
void insgps2center(PositionConf &p, const double insgps_x, const double insgps_y)
{
    p.x = p.x - (insgps_x * cos(p.heading * torad) + insgps_y * sin(p.heading * torad));
    p.y = p.y - (insgps_y * cos(p.heading * torad) - insgps_x * sin(p.heading * torad));
}