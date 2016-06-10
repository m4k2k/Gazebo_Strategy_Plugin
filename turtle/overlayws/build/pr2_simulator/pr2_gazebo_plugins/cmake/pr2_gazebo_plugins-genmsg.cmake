# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "pr2_gazebo_plugins: 2 messages, 1 services")

set(MSG_I_FLAGS "-Ipr2_gazebo_plugins:/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Inav_msgs:/opt/ros/indigo/share/nav_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/indigo/share/sensor_msgs/cmake/../msg;-Ipr2_msgs:/opt/ros/indigo/share/pr2_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Idiagnostic_msgs:/opt/ros/indigo/share/diagnostic_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/indigo/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(pr2_gazebo_plugins_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/PlugCommand.msg" NAME_WE)
add_custom_target(_pr2_gazebo_plugins_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pr2_gazebo_plugins" "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/PlugCommand.msg" ""
)

get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/ModelJointsState.msg" NAME_WE)
add_custom_target(_pr2_gazebo_plugins_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pr2_gazebo_plugins" "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/ModelJointsState.msg" "geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/srv/SetModelsJointsStates.srv" NAME_WE)
add_custom_target(_pr2_gazebo_plugins_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "pr2_gazebo_plugins" "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/srv/SetModelsJointsStates.srv" "geometry_msgs/Quaternion:pr2_gazebo_plugins/ModelJointsState:geometry_msgs/Point:geometry_msgs/Pose"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(pr2_gazebo_plugins
  "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/PlugCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pr2_gazebo_plugins
)
_generate_msg_cpp(pr2_gazebo_plugins
  "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/ModelJointsState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pr2_gazebo_plugins
)

### Generating Services
_generate_srv_cpp(pr2_gazebo_plugins
  "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/srv/SetModelsJointsStates.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/ModelJointsState.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pr2_gazebo_plugins
)

### Generating Module File
_generate_module_cpp(pr2_gazebo_plugins
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pr2_gazebo_plugins
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(pr2_gazebo_plugins_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(pr2_gazebo_plugins_generate_messages pr2_gazebo_plugins_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/PlugCommand.msg" NAME_WE)
add_dependencies(pr2_gazebo_plugins_generate_messages_cpp _pr2_gazebo_plugins_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/ModelJointsState.msg" NAME_WE)
add_dependencies(pr2_gazebo_plugins_generate_messages_cpp _pr2_gazebo_plugins_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/srv/SetModelsJointsStates.srv" NAME_WE)
add_dependencies(pr2_gazebo_plugins_generate_messages_cpp _pr2_gazebo_plugins_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pr2_gazebo_plugins_gencpp)
add_dependencies(pr2_gazebo_plugins_gencpp pr2_gazebo_plugins_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pr2_gazebo_plugins_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(pr2_gazebo_plugins
  "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/PlugCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pr2_gazebo_plugins
)
_generate_msg_lisp(pr2_gazebo_plugins
  "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/ModelJointsState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pr2_gazebo_plugins
)

### Generating Services
_generate_srv_lisp(pr2_gazebo_plugins
  "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/srv/SetModelsJointsStates.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/ModelJointsState.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pr2_gazebo_plugins
)

### Generating Module File
_generate_module_lisp(pr2_gazebo_plugins
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pr2_gazebo_plugins
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(pr2_gazebo_plugins_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(pr2_gazebo_plugins_generate_messages pr2_gazebo_plugins_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/PlugCommand.msg" NAME_WE)
add_dependencies(pr2_gazebo_plugins_generate_messages_lisp _pr2_gazebo_plugins_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/ModelJointsState.msg" NAME_WE)
add_dependencies(pr2_gazebo_plugins_generate_messages_lisp _pr2_gazebo_plugins_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/srv/SetModelsJointsStates.srv" NAME_WE)
add_dependencies(pr2_gazebo_plugins_generate_messages_lisp _pr2_gazebo_plugins_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pr2_gazebo_plugins_genlisp)
add_dependencies(pr2_gazebo_plugins_genlisp pr2_gazebo_plugins_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pr2_gazebo_plugins_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(pr2_gazebo_plugins
  "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/PlugCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pr2_gazebo_plugins
)
_generate_msg_py(pr2_gazebo_plugins
  "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/ModelJointsState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pr2_gazebo_plugins
)

### Generating Services
_generate_srv_py(pr2_gazebo_plugins
  "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/srv/SetModelsJointsStates.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/ModelJointsState.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pr2_gazebo_plugins
)

### Generating Module File
_generate_module_py(pr2_gazebo_plugins
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pr2_gazebo_plugins
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(pr2_gazebo_plugins_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(pr2_gazebo_plugins_generate_messages pr2_gazebo_plugins_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/PlugCommand.msg" NAME_WE)
add_dependencies(pr2_gazebo_plugins_generate_messages_py _pr2_gazebo_plugins_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg/ModelJointsState.msg" NAME_WE)
add_dependencies(pr2_gazebo_plugins_generate_messages_py _pr2_gazebo_plugins_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/srv/SetModelsJointsStates.srv" NAME_WE)
add_dependencies(pr2_gazebo_plugins_generate_messages_py _pr2_gazebo_plugins_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(pr2_gazebo_plugins_genpy)
add_dependencies(pr2_gazebo_plugins_genpy pr2_gazebo_plugins_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS pr2_gazebo_plugins_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pr2_gazebo_plugins)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/pr2_gazebo_plugins
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(pr2_gazebo_plugins_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(pr2_gazebo_plugins_generate_messages_cpp nav_msgs_generate_messages_cpp)
add_dependencies(pr2_gazebo_plugins_generate_messages_cpp sensor_msgs_generate_messages_cpp)
add_dependencies(pr2_gazebo_plugins_generate_messages_cpp pr2_msgs_generate_messages_cpp)
add_dependencies(pr2_gazebo_plugins_generate_messages_cpp geometry_msgs_generate_messages_cpp)
add_dependencies(pr2_gazebo_plugins_generate_messages_cpp diagnostic_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pr2_gazebo_plugins)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/pr2_gazebo_plugins
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(pr2_gazebo_plugins_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(pr2_gazebo_plugins_generate_messages_lisp nav_msgs_generate_messages_lisp)
add_dependencies(pr2_gazebo_plugins_generate_messages_lisp sensor_msgs_generate_messages_lisp)
add_dependencies(pr2_gazebo_plugins_generate_messages_lisp pr2_msgs_generate_messages_lisp)
add_dependencies(pr2_gazebo_plugins_generate_messages_lisp geometry_msgs_generate_messages_lisp)
add_dependencies(pr2_gazebo_plugins_generate_messages_lisp diagnostic_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pr2_gazebo_plugins)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pr2_gazebo_plugins\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/pr2_gazebo_plugins
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(pr2_gazebo_plugins_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(pr2_gazebo_plugins_generate_messages_py nav_msgs_generate_messages_py)
add_dependencies(pr2_gazebo_plugins_generate_messages_py sensor_msgs_generate_messages_py)
add_dependencies(pr2_gazebo_plugins_generate_messages_py pr2_msgs_generate_messages_py)
add_dependencies(pr2_gazebo_plugins_generate_messages_py geometry_msgs_generate_messages_py)
add_dependencies(pr2_gazebo_plugins_generate_messages_py diagnostic_msgs_generate_messages_py)
