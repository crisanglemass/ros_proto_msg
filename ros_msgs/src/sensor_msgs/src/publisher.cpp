#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

int main(int argc, char **argv) {
    // 初始化 ROS 节点
    ros::init(argc, argv, "laser_publisher");

    // 创建 ROS 句柄
    ros::NodeHandle nh;

    // 创建一个发布者对象
    ros::Publisher pub = nh.advertise<sensor_msgs::LaserScan>("scan", 10);

    // 创建一个 LaserScan 消息对象
    sensor_msgs::LaserScan msg;

    // 填充 LaserScan 消息的字段
    msg.header.frame_id = "laser_frame";
    msg.angle_min = -M_PI / 2;  // 从-90度开始
    msg.angle_max = M_PI / 2;   // 到90度结束
    msg.angle_increment = M_PI / 180; // 1度的增量
    msg.time_increment = 0.001;  // 1毫秒的增量
    msg.scan_time = 0.1;  // 0.1秒的扫描时间
    msg.range_min = 0.0;  // 最小测量范围
    msg.range_max = 10.0;  // 最大测量范围
    // 假设只有一组距离测量数据，用于演示
    msg.ranges.push_back(1.0);
    msg.intensities.push_back(100);

    ros::Rate loop_rate(1); // 发布频率为1Hz

    while (ros::ok()) {
        // 记录发布消息的时间戳
        msg.header.stamp = ros::Time::now();

        // 发布 LaserScan 消息
        pub.publish(msg);

        // 延时至下一个周期
        loop_rate.sleep();
    }

    return 0;
}
