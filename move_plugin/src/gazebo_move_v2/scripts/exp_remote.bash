#!/bin/bash

# experimental for relay / use the strategy plugin with simulation and hardware simultaneously
export ROS_IP=192.168.137.9 # local ip
export TURTLEBOT_GAZEBO_MAP_FILE=~/Gazebo_Strategy_Plugin/move_plugin/src/gazebo_move_v2/maps/empty.yaml
export TURTLEBOT_GAZEBO_WORLD_FILE=/opt/ros/indigo/share/turtlebot_gazebo/worlds/empty.world

roslaunch gazebo_move_v2 multi_turtle.launch remote:=true
