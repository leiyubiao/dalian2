cd ~/catkin_ws/src \
&& git clone ...  \
&& cd .. \
&& catkin_make \
&& source devel/setup.bash \
&& rospack profile \
&& roslaunch hybrid_astar manual.launch
&& rosrun stanley_controller stanley_controller
&& rosrun rqt_graph rqt_graph
