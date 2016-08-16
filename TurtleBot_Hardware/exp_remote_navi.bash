#!/bin/bash

# 2016/08/14
# Markus L
# for experimental remote setup

export TURTLEBOT_MAP_FILE="$PWD/empty.yaml"

echo first start
echo roslaunch turtlebot_bringup minimal.launch
echo wait 1 minute, then start
echo roslaunch turtlebot_navigation amcl_demo.launch
echo in a second terminal tab