cmake_minimum_required(VERSION 2.8.3 FATAL_ERROR)
project(gazebo_move_v2)

#optimized for gazebo2

#SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/../CMakeModules)

include (FindPkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules(GAZEBO gazebo)
  pkg_check_modules(OGRE OGRE)
else()
  message(SEND_ERROR "can't find pkgconfig")
endif()

# /usr/lib/x86_64-linux-gnu/pkgconfig/


## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  roscpp
)

if(UNIX)
	if(EXISTS "/usr/share/OGRE/cmake/modules")
	  set(CMAKE_MODULE_PATH "/usr/share/OGRE/cmake/modules;${CMAKE_MODULE_PATH}")
	  message("appending OGRE cmake module path")
	else()
	  message(SEND_ERROR "Failed to find OGRE module path.")
	endif(EXISTS "/usr/share/OGRE/cmake/modules")
endif(UNIX)

## System dependencies are found with CMake's conventions
#include(FindBoost)
#find_package(Boost ${MIN_BOOST_VERSION} REQUIRED system filesystem regex)
find_package(Boost REQUIRED)
find_package(Qt4 REQUIRED)
find_package(Protobuf REQUIRED)
find_package(gazebo REQUIRED)
find_package(OGRE REQUIRED)
#find_package(OIS REQUIRED)



if(NOT QT4_FOUND)
    message(SEND_ERROR "Failed to find QT4.")
endif()

if(NOT Boost_FOUND)
    message(SEND_ERROR "Failed to find Boost.")
endif()

if(NOT PROTOBUF_FOUND)
    message(SEND_ERROR "Failed to find PROTOBUF.")
endif()

if(NOT OGRE_FOUND)
    message(SEND_ERROR "Failed to find OGRE.")
endif()

#message(WARNING "ogre_incl: ${OGRE_INCLUDE_DIRS}")
#message(WARNING "ogre_lib: ${OGRE_LIBRARIES}")
#message(WARNING "ogre_lib_dirs: ${OGRE_LIBRARY_DIRS}")


#if(NOT OIS_FOUND)
#    message(SEND_ERROR "Failed to find OIS.")
#endif()

include (${QT_USE_FILE})
#add_definitions(${QT_DEFINITIONS})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS} ${QT_DEFINITIONS} -Wall")
message(WARNING "the compiler flags are:")
message(WARNING "${CMAKE_CXX_FLAGS}")
#include(FindBoost)
#find_package(Boost ${MIN_BOOST_VERSION} REQUIRED system filesystem regex)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
# )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
#catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES gazebo_plug
#  CATKIN_DEPENDS gazebo_ros roscpp
#  DEPENDS system_lib
#)

catkin_package(
  DEPENDS
    roscpp
    gazebo_ros
)


#QT4_WRAP_CPP(headers_MOC src/${PROJECT_NAME}.hh)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
#include_directories(
#  ${catkin_INCLUDE_DIRS}
#)


include_directories(
    ${Boost_INCLUDE_DIR}
    ${catkin_INCLUDE_DIRS}
    ${OGRE_INCLUDE_DIRS}
    #/usr/include/OGRE/Terrain #workaround for OgreTerrainPaging.h:33:35: fatal error: OgrePagedWorldSection.h: No such file or directory
    /usr/include/OGRE/Paging #workaround for OgreTerrainPaging.h:33:35: fatal error: OgrePagedWorldSection.h: No such file or directory
    #${OGRE_Overlay_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS})

## Declare a C++ library
# add_library(gazebo_plug
#   src/${PROJECT_NAME}/gazebo_plug.cpp
# )
#add_library(${PROJECT_NAME} src/gazebo_move.cpp)

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(gazebo_plug ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
# add_executable(gazebo_plug_node src/gazebo_plug_node.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(gazebo_plug_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(gazebo_plug_node
#   ${catkin_LIBRARIES}
# )

# target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})

link_directories(
    ${GAZEBO_LIBRARY_DIRS}
    ${OGRE_LIBRARY_DIRS})


add_library(${PROJECT_NAME} SHARED ${headers_MOC}
  src/${PROJECT_NAME}.cc)

target_link_libraries(${PROJECT_NAME}
    ${GAZEBO_LIBRARIES}
    ${OGRE_LIBRARIES}
    #${OGRE_Overlay_LIBRARIES}
    ${QT_LIBRARIES}
    ${PROTOBUF_LIBRARIES}
    ${catkin_LIBRARIES})


#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS gazebo_plug gazebo_plug_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_gazebo_plug.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
