# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "perception_msgs: 5 messages, 0 services")

set(MSG_I_FLAGS "-Iperception_msgs:/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(perception_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg" NAME_WE)
add_custom_target(_perception_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "perception_msgs" "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg" ""
)

get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg" NAME_WE)
add_custom_target(_perception_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "perception_msgs" "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg" "perception_msgs/ts_Geometry:perception_msgs/ts_Object:std_msgs/Header:perception_msgs/ts_3DPose"
)

get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg" NAME_WE)
add_custom_target(_perception_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "perception_msgs" "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg" NAME_WE)
add_custom_target(_perception_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "perception_msgs" "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg" "perception_msgs/ts_Geometry:perception_msgs/ts_3DPose"
)

get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg" NAME_WE)
add_custom_target(_perception_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "perception_msgs" "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/perception_msgs
)
_generate_msg_cpp(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg"
  "${MSG_I_FLAGS}"
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/perception_msgs
)
_generate_msg_cpp(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg"
  "${MSG_I_FLAGS}"
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/perception_msgs
)
_generate_msg_cpp(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/perception_msgs
)
_generate_msg_cpp(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/perception_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(perception_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/perception_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(perception_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(perception_msgs_generate_messages perception_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_cpp _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_cpp _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_cpp _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_cpp _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_cpp _perception_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(perception_msgs_gencpp)
add_dependencies(perception_msgs_gencpp perception_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS perception_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/perception_msgs
)
_generate_msg_eus(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg"
  "${MSG_I_FLAGS}"
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/perception_msgs
)
_generate_msg_eus(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg"
  "${MSG_I_FLAGS}"
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/perception_msgs
)
_generate_msg_eus(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/perception_msgs
)
_generate_msg_eus(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/perception_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(perception_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/perception_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(perception_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(perception_msgs_generate_messages perception_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_eus _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_eus _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_eus _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_eus _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_eus _perception_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(perception_msgs_geneus)
add_dependencies(perception_msgs_geneus perception_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS perception_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/perception_msgs
)
_generate_msg_lisp(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg"
  "${MSG_I_FLAGS}"
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/perception_msgs
)
_generate_msg_lisp(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg"
  "${MSG_I_FLAGS}"
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/perception_msgs
)
_generate_msg_lisp(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/perception_msgs
)
_generate_msg_lisp(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/perception_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(perception_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/perception_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(perception_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(perception_msgs_generate_messages perception_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_lisp _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_lisp _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_lisp _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_lisp _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_lisp _perception_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(perception_msgs_genlisp)
add_dependencies(perception_msgs_genlisp perception_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS perception_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/perception_msgs
)
_generate_msg_nodejs(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg"
  "${MSG_I_FLAGS}"
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/perception_msgs
)
_generate_msg_nodejs(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg"
  "${MSG_I_FLAGS}"
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/perception_msgs
)
_generate_msg_nodejs(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/perception_msgs
)
_generate_msg_nodejs(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/perception_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(perception_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/perception_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(perception_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(perception_msgs_generate_messages perception_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_nodejs _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_nodejs _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_nodejs _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_nodejs _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_nodejs _perception_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(perception_msgs_gennodejs)
add_dependencies(perception_msgs_gennodejs perception_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS perception_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/perception_msgs
)
_generate_msg_py(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg"
  "${MSG_I_FLAGS}"
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/perception_msgs
)
_generate_msg_py(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg"
  "${MSG_I_FLAGS}"
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg;/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/perception_msgs
)
_generate_msg_py(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/perception_msgs
)
_generate_msg_py(perception_msgs
  "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/perception_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(perception_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/perception_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(perception_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(perception_msgs_generate_messages perception_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_3DPose.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_py _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_ObjectList.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_py _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_LKA.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_py _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Object.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_py _perception_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg/ts_Geometry.msg" NAME_WE)
add_dependencies(perception_msgs_generate_messages_py _perception_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(perception_msgs_genpy)
add_dependencies(perception_msgs_genpy perception_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS perception_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/perception_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/perception_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(perception_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/perception_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/perception_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(perception_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/perception_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/perception_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(perception_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/perception_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/perception_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(perception_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/perception_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/perception_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/perception_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(perception_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
