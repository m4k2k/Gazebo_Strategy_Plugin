cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

include (FindPkgConfig)
if (PKG_CONFIG_FOUND)
  pkg_check_modules(GAZEBO gazebo)
endif()

find_package (Qt4)
find_package(Protobuf REQUIRED)
find_package(gazebo REQUIRED)


include (${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

include(FindBoost)
find_package(Boost ${MIN_BOOST_VERSION} REQUIRED system filesystem regex)


include_directories(SYSTEM ${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")


##########################################################################################################
##########################################################################################################



add_library(system_robot SHARED system_robot.cc)
target_link_libraries(system_robot ${GAZEBO_LIBRARIES} ${Boost_LIBRARIES} ${PROTOBUF_LIBRARIES})

#add_custom_command(TARGET system_robot POST_BUILD        # Adds a post-build event to MyTest
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
#            "${PROJECT_SOURCE_DIR}/build/libsystem_robot.so"      # <--this is in-file
#                    ../../gazebo_plugins_build/)                 # <--this is out-file PATH





##########################################################################################################
##########################################################################################################


set(OutputLibName "gui_example_spawn_widget")
set(InputLibName "GUIExampleSpawnWidget")

QT4_WRAP_CPP(headers_MOC ${InputLibName}.hh)

add_library(${OutputLibName} SHARED ${headers_MOC}
  ${InputLibName}.cc)
target_link_libraries(${OutputLibName} ${GAZEBO_LIBRARIES}
    ${QT_LIBRARIES}
    ${PROTOBUF_LIBRARIES})

#add_custom_command(TARGET ${OutputLibName} POST_BUILD        # Adds a post-build event to MyTest
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
#            "${PROJECT_SOURCE_DIR}/build/lib${OutputLibName}.so"      # <--this is in-file
#                    ../../gazebo_plugins_build/)                 # <--this is out-file PATH



##########################################################################################################
##########################################################################################################


add_library(system_gui SHARED system_gui.cc)
target_link_libraries(system_gui ${GAZEBO_LIBRARIES})

#add_custom_command(TARGET system_gui POST_BUILD        # Adds a post-build event to MyTest
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
#            "${PROJECT_SOURCE_DIR}/build/libsystem_gui.so"      # <--this is in-file
#                    ../../gazebo_plugins_build/)                 # <--this is out-file PATH



##########################################################################################################
##########################################################################################################



add_library(system_mouse SHARED system_mouse.cc)
target_link_libraries(system_mouse ${GAZEBO_LIBRARIES})

#add_custom_command(TARGET system_mouse POST_BUILD        # Adds a post-build event to MyTest
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
#            "${PROJECT_SOURCE_DIR}/build/libsystem_mouse.so"      # <--this is in-file
#                    ../../gazebo_plugins_build/)                 # <--this is out-file PATH

