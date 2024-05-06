/*
    需求: 循环发布人的信息

*/

#include "ros/ros.h"
#include "transfer_img/Image.h"
#include "transform_img2str.h"
int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "");

  // 1.初始化 ROS 节点
  ros::init(argc, argv, "talker_person");

  // 2.创建 ROS 句柄
  ros::NodeHandle nh;

  // 3.创建发布者对象
  ros::Publisher pub =
      nh.advertise<transfer_img::Image>("chatter_person", 1000);

  ros::Time right_now = ros::Time::now();
  transfer_img::Image p;

  // 读取base64
  std::string image_path = "/work/images/image.jpg";
  std::string base64String = imageToBase64(image_path);

  p.id = 0;
  p.name = "test";
  p.msg_type = "test_message";
  p.encode_msg = "1";

  ros::Rate r(10);
  while (ros::ok()) {
    ros::Time right_now = ros::Time::now();
    p.timestamp = right_now.toSec();
    pub.publish(p);
    r.sleep();
    ros::spinOnce();
  }

  return 0;
}
