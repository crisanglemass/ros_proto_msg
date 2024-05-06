/*
 * Copyright (C) 2008, Morgan Quigley and Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the
 * names of its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

// %Tag(FULLTEXT)%
#include <ros/protobuffer_traits.h>
#include <ros/serialization_protobuffer.h>
#include "ros/ros.h"
#include "publish_info.pb.h"
#include <fstream> 
#include <ros/package.h> 
#include <sys/stat.h> 
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
// %Tag(CALLBACK)%
// void chatterCallback(
//     const boost::shared_ptr<huizhang::sample::PublishInfo> &msg) {
//   std::cerr << "I heard: " << msg->DebugString() << std::endl;
//   std::string def =
//       ros::message_traits::Definition<huizhang::sample::PublishInfo>::value();
//   std::cout << "def: " << def << std::endl;
// }
void chatterCallback(
    const ros::MessageEvent<huizhang::sample::PublishInfo> &msg) {
  // std::cerr << "I heard: " << msg.getMessage()->DebugString() << std::endl;
  // std::string def =
  //     ros::message_traits::Definition<huizhang::sample::PublishInfo>::value();
  // std::cout << "def: " << def << std::endl;
  double timestamp = msg.getMessage()->timestamp();
  ros::Time right_time = ros::Time::now();
  double timeDiff = right_time.toSec() - timestamp;
  ROS_INFO("Time difference: %f mseconds", timeDiff * 1e3);


  //store file to .txt 
  std::string filePath = "./data/timediff.txt";

  // 打开文件并写入时间差
  std::ofstream outFile(filePath, std::ios::app);
  if (outFile.is_open()) {
    outFile << "Time difference: " << timeDiff * 1e3 << " mseconds\n";
    outFile.close();
  } else {
    ROS_ERROR("Failed to open file: %s", filePath.c_str());
  }
}
// %EndTag(CALLBACK)%

int main(int argc, char **argv) {
  ros::init(argc, argv, "pb_listener");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the
   * last NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing.  Messages are passed to a callback function, here
   * called chatterCallback.  subscribe() returns a Subscriber object that you
   * must hold on to until you want to unsubscribe.  When all copies of the
   * Subscriber object go out of scope, this callback will automatically be
   * unsubscribed from this topic.
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.  If messages are arriving faster than they are being processed, this
   * is the number of messages that will be buffered up before beginning to
   * throw away the oldest ones.
   */
  // %Tag(SUBSCRIBER)%
  ros::Subscriber sub = n.subscribe("/ros_proto_buf", 1000, chatterCallback);
  // %EndTag(SUBSCRIBER)%

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).
   * ros::spin() will exit when Ctrl-C is pressed, or the node is shutdown by
   * the master.
   */
  // %Tag(SPIN)%
  ros::spin();
  // %EndTag(SPIN)%

  return 0;
}
// %EndTag(FULLTEXT)%
