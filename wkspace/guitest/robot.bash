#!/bin/bash

echo "starting gazebo server and client.."
gzserver & gzclient -g libsystem_robot.so --verbose
sleep 2
echo "killing gazebo server"
killall gzserver
sleep 1
echo "done"
