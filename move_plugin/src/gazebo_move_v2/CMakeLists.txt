cmake_minimum_required(VERSION 2.8.3 FATAL_ERROR)
project(gazebo_move_v2)

Set(ALL_TARGETS "" CACHE INTERNAL "")

function(Add_library NAME)
  Set(ALL_TARGETS ${ALL_TARGETS} "${ARGN}" CACHE INTERNAL "ALL_TARGETS")
  _add_library(${NAME} ${ARGN})
endfunction()

function(Add_executable NAME)
  Set(ALL_TARGETS ${ALL_TARGETS} "${ARGN}" CACHE INTERNAL "ALL_TARGETS")
  _add_executable(${NAME} ${ARGN})
endfunction()

add_custom_target(BUILD_SUCCESSFUL ALL
                  DEPENDS ${ALL_TARGETS}
                  COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --red --bold "~~~~ BUILD STAMP: ${PROJECT_NAME}"
                  COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --red --bold `date +'~~~~_%Y-%m-%d ~~~~_%H:%M:%S'`
                  )

if(NOT WIN32)
    string(ASCII 27 Esc)
    set(ColourReset "${Esc}[m")
    set(BoldRed     "${Esc}[1;31m")
endif()


#SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/../CMakeModules) #not working for gazebo2

include (FindPkgConfig)
if (PKG_CONFIG_FOUND)
    pkg_check_modules(GAZEBO gazebo)
    pkg_check_modules(OGRE OGRE)
else()
    message(SEND_ERROR "can't find pkgconfig")
endif()

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
    gazebo_ros
    roscpp)

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
message(STATUS "the compiler flags are: ${CMAKE_CXX_FLAGS}")

#include(FindBoost)
#find_package(Boost ${MIN_BOOST_VERSION} REQUIRED system filesystem regex)

catkin_package(
    DEPENDS roscpp
    gazebo_ros)


#QT4_WRAP_CPP(headers_MOC src/${PROJECT_NAME}.hh)

###########
## Build ##
###########

include_directories(
    ${Boost_INCLUDE_DIR}
    ${catkin_INCLUDE_DIRS}
    ${OGRE_INCLUDE_DIRS}
#/usr/include/OGRE/Terrain #workaround for OgreTerrainPaging.h:33:35: fatal error: OgrePagedWorldSection.h: No such file or directory
    /usr/include/OGRE/Paging #workaround for OgreTerrainPaging.h:33:35: fatal error: OgrePagedWorldSection.h: No such file or directory
#${OGRE_Overlay_INCLUDE_DIRS}
    ${GAZEBO_INCLUDE_DIRS})


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
    ${catkin_LIBRARIES}
    )


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
string(TIMESTAMP TIME_END_FORMAT "%Y-%m-%d %H:%M:%S")
message("${BoldRed}## cmake build done ${PROJECT_NAME} end time: ${TIME_END_FORMAT}${ColourReset}")
