/*
 * Copyright (C) 2009, Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
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

#ifndef ROSLIB_SERIALIZED_MESSAGE_H
#define ROSLIB_SERIALIZED_MESSAGE_H

#include <boost/shared_array.hpp>
#include <boost/shared_ptr.hpp>

#include "roscpp_serialization_macros.h"

namespace ros {

class ROSCPP_SERIALIZATION_DECL SerializedMessage {
 public:
  // 存储字节流大小和起始位置
  boost::shared_array<uint8_t> buf;  // 存储字节流，智能指针指向存储字节流的地址
  size_t num_bytes;        // 字节流的大小
  uint8_t* message_start;  // 字节流起始位置的指针
  // 反序列化对象
  boost::shared_ptr<void const> message;
  // 对象的类型，c++的对象
  const std::type_info* type_info;
  // ros在发布消息的源码流程
  // void publish(const boost::shared_ptr<M> message){
  //   m.type_info=&typeid(M);
  //   m.message=message;
  // }

  SerializedMessage()
      : buf(boost::shared_array<uint8_t>()),
        num_bytes(0),
        message_start(0),
        type_info(0)  // 反序列化对象的类型，原数据
  {}

  SerializedMessage(boost::shared_array<uint8_t> buf, size_t num_bytes)
      : buf(buf),
        num_bytes(num_bytes),
        message_start(buf ? buf.get() : 0),
        type_info(0) {}
};

}  // namespace ros

#endif  // ROSLIB_SERIALIZED_MESSAGE_H
