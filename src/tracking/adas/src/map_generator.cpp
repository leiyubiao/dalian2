#include "rtk_map.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "map_generator");
    ros::NodeHandle nh;
    rtk_map map_(nh);
}