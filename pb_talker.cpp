#include <ros/protobuffer_traits.h>
#include <ros/serialization_protobuffer.h>
#include "ros/ros.h"
#include "publish_info.pb.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "pb_talker");
  ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME,
                                 ros::console::levels::Debug);
  ros::NodeHandle n;

  ros::Publisher pub =
      n.advertise<huizhang::sample::PublishInfo>("/ros_proto_buf", 1000);

  ros::Rate loop_rate(10);
  
  huizhang::sample::PublishInfo proto_msg_info;
  proto_msg_info.set_name("test");
  proto_msg_info.set_message_type("test_message");
  proto_msg_info.set_publish_msg("1");
  int count = 0;
  while (ros::ok()) {
    ros::Time right_time=ros::Time::now();
    proto_msg_info.set_timestamp(right_time.toSec());
    pub.publish(proto_msg_info);
    // std::cerr << "DebugMsg: " << proto_msg_info.DebugString() << std::endl;
    // uint32_t length = ros::serialization::Serializer<huizhang::sample::PublishInfo>::serializedLength(proto_msg_info);
    // ROS_INFO("Serialized length of the message: %u", length);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  return 0;
}
