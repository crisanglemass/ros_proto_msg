#!/bin/bash
# 检查是否有roscore进程在运行
if pgrep -x "roscore" > /dev/null; then
    echo "roscore is running."
else
    echo "roscore is not running. Start it"
    exit 1
fi

cd /work/ros_msgs
rosrun myproject pb_talker