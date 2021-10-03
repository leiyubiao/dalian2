#include "PID_Controller.h"

int main(int argc, char** argv) {

  ros::init(argc, argv, "Controller");

  Control::PID_Controller pidController;

  ros::Rate loop_rate(50); // 50Hz
  while(ros::ok())
  {
      ros::spinOnce();     
      loop_rate.sleep();
  }

  return 0;
}
