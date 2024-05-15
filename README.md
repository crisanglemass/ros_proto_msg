# ros_proto_msg

# Objective
Based on the SFINAE mechanism in C++ template programming, we modified the underlying code of the core libraries roscpp_serialization and roscpp_traits in roscpp. This allows the ros-protobuf-bridge to be compatible with both native ROS messages and Protobuf messages simultaneously.

MSG and Protobuf camparasion by single bytes, sensor_msgs and large scale image (10hz , 1000 epochs) 

Average latency (ms)

1. single bytes         (1 bytes)  0.31->0.26

2. sensor_msgs          (36bytes)  0.65->0.58

3. large scale image    (981kb)    1.21->0.87
