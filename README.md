# ros_proto_msg


MSG and Protobuf camparasion by single bytes, sensor_msgs and large scale image (10hz , 1000 epochs) 

Average latency (ms)

1. single bytes         (1 bytes)  0.31->0.26

2. sensor_msgs          (36bytes)  0.65->0.58

3. large scale image    (981kb)    1.21->0.87
