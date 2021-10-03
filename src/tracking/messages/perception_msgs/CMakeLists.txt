cmake_minimum_required(VERSION 2.8.3)
project(perception_msgs)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS  
  message_generation
  roscpp
)


add_message_files(
  FILES
  ts_3DPose.msg
  ts_Geometry.msg
  ts_LKA.msg
  ts_Object.msg
  ts_ObjectList.msg
)


generate_messages(DEPENDENCIES
  std_msgs
)


catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
