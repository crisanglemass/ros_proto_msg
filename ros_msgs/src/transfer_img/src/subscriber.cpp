/*target_link
    需求: 订阅人的信息

*/

#include <sys/stat.h>

#include <fstream>

#include <ros/package.h>

#include "ros/ros.h"
#include "transfer_img/Image.h"

void doImage(const transfer_img::Image::ConstPtr& msg) {
  if (msg->encode_msg.size() > 0) {
    std::string output_image_path = "output_image.jpg";
    // saveImageFromBase64(msg->encode_msg, output_image_path);
  }

  // 计算发布和订阅之间的时间差
  ros::Time right_now = ros::Time::now();
  double timestamp = msg->timestamp;
  double timediff = right_now.toSec() - timestamp;
  ROS_INFO("Time difference between pub and sub: %f mseconds", timediff * 1e3);

  // 拼接文件路径
  std::string filePath = "./src/transfer_img/data/timediff.txt";

  // 打开文件并写入时间差
  std::ofstream outFile(filePath, std::ios::app);
  if (outFile.is_open()) {
    outFile << "Time difference: " << timediff * 1e3 << " mseconds\n";
    outFile.close();
  } else {
    ROS_ERROR("Failed to open file: %s", filePath.c_str());
  }
}

int main(int argc, char* argv[]) {
  setlocale(LC_ALL, "");

  // 1.初始化 ROS 节点
  ros::init(argc, argv, "listener_person");
  // 2.创建 ROS 句柄
  ros::NodeHandle nh;
  // 3.创建订阅对象
  ros::Subscriber sub =
      nh.subscribe<transfer_img::Image>("chatter_person", 10, doImage);

  // 4.回调函数中处理 person

  // 5.ros::spin();
  ros::spin();
  return 0;
}
