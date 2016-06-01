#!/bin/bash

echo "starting gazebo server and client.."
gzserver & gzclient -g libsystem_gui.so --verbose
sleep 2
echo "killing gazebo server"
killall gzserver
sleep 1
reset
echo "done"
