cmake_minimum_required(VERSION 2.8.3)
project(pid_controller)
add_compile_options(-std=c++14)
find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    std_msgs
    location_msgs
    control_msgs
    )


set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/PID_Controller.cpp
    )
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/PID_Controller.h
    )

## Declare a catkin package
catkin_package(
  INCLUDE_DIRS include
  #location_msgs
)

include_directories(
    include 
    SYSTEM 
    ${catkin_INCLUDE_DIRS}
)

add_executable(pid_controller src/main.cpp ${HEADERS} ${SOURCES})
target_link_libraries(pid_controller ${catkin_LIBRARIES})

add_dependencies(pid_controller ${catkin_EXPORTED_TARGETS})