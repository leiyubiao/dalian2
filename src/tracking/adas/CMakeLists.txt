cmake_minimum_required(VERSION 3.8)
project(adas_control)
add_compile_options(-std=c++14)
find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    std_msgs
    tf
    location_msgs
    control_msgs
    geometry_msgs
    )
find_package(PythonLibs 2.7)


## Declare a catkin package
catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS
  roscpp
  std_msgs
  location_msgs
  control_msgs
  geometry_msgs
)

include_directories(
	include
  ${EIGEN3_INCLUDE_DIR}
	${catkin_INCLUDE_DIRS}
)

add_executable(map_tracking
    src/map_tracking.cpp
    src/adas_control.cpp
    src/pid_control.cpp
    src/adas_utils.cpp
    src/plan.cpp)
target_include_directories(map_tracking PRIVATE ${PYTHON_INCLUDE_DIRS})
# target_link_libraries(map_tracking PRIVATE ${PYTHON_LIBRARIES})

target_link_libraries(map_tracking PRIVATE
   ${PYTHON_LIBRARIES} )

target_link_libraries(map_tracking PUBLIC   ${catkin_LIBRARIES})

# add_dependencies(map_tracking ${catkin_EXPORTED_TARGETS})


add_executable(map_generator
    src/map_generator.cpp
    src/rtk_map.cpp
    src/adas_utils.cpp)

target_link_libraries(map_generator
  ${catkin_LIBRARIES}
)

add_dependencies(map_generator ${catkin_EXPORTED_TARGETS})





