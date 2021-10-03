#include "adas_control.h"
#include "plan.h"
#include <vector>
#include <iostream>
#include "matplotlibcpp.h"
using namespace std;
namespace plt = matplotlibcpp;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "map_tracking");
    ros::NodeHandle nh;
    ros::Rate loop_rate(50);
    ros::Publisher trajectoryPub;
    trajectoryPub = nh.advertise<nav_msgs::Path>("/real_trajectory", 10);
    

    control_space::Controller control_(nh);
    adas_plan map_(nh);    
    map_.GetRouteFromFile();
    nav_msgs::Path myPath;

    myPath.header.frame_id = "/map";
    vector<double> xRef;
    vector<double> yRef;
    vector<double> xReal;
    // xReal.reserve(INT_MAX / 8);
    // yReal.reserve(INT_MAX / 8);
    vector<double> yReal;

    for (const auto& point : map_.route_data_) {
        xRef.push_back(point.x);
        yRef.push_back(point.y);

    }
    
    while(ros::ok())
    {
        control_.adas_tracking(map_.car_, map_.route_data_);
        geometry_msgs::PoseStamped aPos;
        xReal.push_back(control_.xy_pos.x);
        yReal.push_back(control_.xy_pos.y);
        
        aPos.pose.position.x = control_.xy_pos.x;
        aPos.pose.position.y = control_.xy_pos.y;
        aPos.pose.position.z = control_.xy_pos.z;
        aPos.header.frame_id = "/map";
        myPath.poses.push_back(aPos);
        trajectoryPub.publish(myPath);
        int size = myPath.poses.size();
        // printf("size ============ %d ,    x = %lf \n", control_.xy_pos.x);

        // control_.Visualization(map_.car_, map_.route_data_[control_.nearest_point_index_]);
        loop_rate.sleep();
        ros::spinOnce();
 
    }

  plt::named_plot("ref_trajectory", xRef, yRef);
  plt::named_plot("vehicle_pose", xReal, yReal);
  //plt::named_plot("vehicle_speed", x_vehicle, v_vehicle);


//   plt::ylim<double>(-20.0, 22.0);
  //plt::plot(x ,y);
  plt::title("clean car");
  plt::legend();
  plt::grid(true);
  plt::show();

}
