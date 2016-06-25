# Install script for directory: /home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/install")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  INCLUDE("/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/build/kobuki/kobuki_testsuite/catkin_generated/safe_execute_install.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/build/kobuki/kobuki_testsuite/catkin_generated/installspace/kobuki_testsuite.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kobuki_testsuite/cmake" TYPE FILE FILES
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/build/kobuki/kobuki_testsuite/catkin_generated/installspace/kobuki_testsuiteConfig.cmake"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/build/kobuki/kobuki_testsuite/catkin_generated/installspace/kobuki_testsuiteConfig-version.cmake"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kobuki_testsuite" TYPE FILE FILES "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/package.xml")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kobuki_testsuite" TYPE PROGRAM FILES
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/inf_rotation.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_analog_input.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_battery_voltage.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_events.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_gyro.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_led_array.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_rotation.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_sounds.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/scan_angle.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_battery"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_digital_output.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_external_power.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_input.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_output.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_safewandering.py"
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki/kobuki_testsuite/scripts/test_translation.py"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

