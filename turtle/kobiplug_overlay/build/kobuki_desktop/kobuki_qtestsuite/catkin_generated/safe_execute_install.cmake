execute_process(COMMAND "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/build/kobuki_desktop/kobuki_qtestsuite/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/build/kobuki_desktop/kobuki_qtestsuite/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
