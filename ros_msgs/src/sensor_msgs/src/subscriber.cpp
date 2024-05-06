#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include <fstream> 
#include <ros/package.h> 
#include <sys/stat.h> 

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
    // 输出 LaserScan 消息的一些信息
    ROS_INFO("Received LaserScan message:");
    ROS_INFO("Frame ID: %s", msg->header.frame_id.c_str());
    ROS_INFO("Angle Min: %f", msg->angle_min);
    ROS_INFO("Angle Max: %f", msg->angle_max);
    ROS_INFO("Angle Increment: %f", msg->angle_increment);
    ROS_INFO("Time Increment: %f", msg->time_increment);
    ROS_INFO("Scan Time: %f", msg->scan_time);
    ROS_INFO("Range Min: %f", msg->range_min);
    ROS_INFO("Range Max: %f", msg->range_max);

    // 输出距离测量值和强度测量值
    for (size_t i = 0; i < msg->ranges.size(); ++i) {
        ROS_INFO("Range[%zu]: %f", i, msg->ranges[i]);
    }
    for (size_t i = 0; i < msg->intensities.size(); ++i) {
        ROS_INFO("Intensity[%zu]: %f", i, msg->intensities[i]);
    }

    // 计算发布和订阅之间的时间差
    ros::Time currentTime = ros::Time::now();
    ros::Duration timeDiff = currentTime - msg->header.stamp;
    ROS_INFO("Time difference between pub and sub: %f mseconds", timeDiff.toSec()*1e3);

    // 拼接文件路径
    std::string filePath ="./src/sensor_msgs/data/timediff.txt";

    // 打开文件并写入时间差
    std::ofstream outFile(filePath, std::ios::app);
    if (outFile.is_open()) {
        outFile << "Time difference: " << timeDiff.toSec()*1e3 << " mseconds\n";
        outFile.close();
    } else {
        ROS_ERROR("Failed to open file: %s", filePath.c_str());
    }


}

int main(int argc, char **argv) {
    // 初始化 ROS 节点
    ros::init(argc, argv, "laser_subscriber");

    // 创建 ROS 句柄
    ros::NodeHandle nh;

    // 创建一个subscriber对象，订阅名为“scan”的消息
    ros::Subscriber sub = nh.subscribe<sensor_msgs::LaserScan>("scan", 10, scanCallback);

    // 循环等待接收消息
    ros::spin();

    return 0;
}
