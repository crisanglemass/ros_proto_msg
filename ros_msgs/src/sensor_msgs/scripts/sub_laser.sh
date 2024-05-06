#!/bin/bash
# 检查是否有roscore进程在运行
if pgrep -x "roscore" > /dev/null; then
    echo "roscore is running."
else
    echo "roscore is not running. Start it"
    exit 1
fi

if [ "$#" -gt 0 ]; then
    catkin_make    
fi
cd /work/ros_msgs
source ./devel/setup.bash
rosrun sensor_msgs Sub_Laser