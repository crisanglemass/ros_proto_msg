// Generated by gencpp from file transfer_img/Image.msg
// DO NOT EDIT!


#ifndef TRANSFER_IMG_MESSAGE_IMAGE_H
#define TRANSFER_IMG_MESSAGE_IMAGE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace transfer_img
{
template <class ContainerAllocator>
struct Image_
{
  typedef Image_<ContainerAllocator> Type;

  Image_()
    : id(0)
    , name()
    , msg_type()
    , encode_msg()
    , timestamp(0.0)  {
    }
  Image_(const ContainerAllocator& _alloc)
    : id(0)
    , name(_alloc)
    , msg_type(_alloc)
    , encode_msg(_alloc)
    , timestamp(0.0)  {
  (void)_alloc;
    }



   typedef uint16_t _id_type;
  _id_type id;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _name_type;
  _name_type name;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _msg_type_type;
  _msg_type_type msg_type;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _encode_msg_type;
  _encode_msg_type encode_msg;

   typedef double _timestamp_type;
  _timestamp_type timestamp;





  typedef boost::shared_ptr< ::transfer_img::Image_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::transfer_img::Image_<ContainerAllocator> const> ConstPtr;

}; // struct Image_

typedef ::transfer_img::Image_<std::allocator<void> > Image;

typedef boost::shared_ptr< ::transfer_img::Image > ImagePtr;
typedef boost::shared_ptr< ::transfer_img::Image const> ImageConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::transfer_img::Image_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::transfer_img::Image_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::transfer_img::Image_<ContainerAllocator1> & lhs, const ::transfer_img::Image_<ContainerAllocator2> & rhs)
{
  return lhs.id == rhs.id &&
    lhs.name == rhs.name &&
    lhs.msg_type == rhs.msg_type &&
    lhs.encode_msg == rhs.encode_msg &&
    lhs.timestamp == rhs.timestamp;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::transfer_img::Image_<ContainerAllocator1> & lhs, const ::transfer_img::Image_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace transfer_img

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::transfer_img::Image_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::transfer_img::Image_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::transfer_img::Image_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::transfer_img::Image_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::transfer_img::Image_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::transfer_img::Image_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::transfer_img::Image_<ContainerAllocator> >
{
  static const char* value()
  {
    return "744347aa4b3e0b8a8d56e91de0a07387";
  }

  static const char* value(const ::transfer_img::Image_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x744347aa4b3e0b8aULL;
  static const uint64_t static_value2 = 0x8d56e91de0a07387ULL;
};

template<class ContainerAllocator>
struct DataType< ::transfer_img::Image_<ContainerAllocator> >
{
  static const char* value()
  {
    return "transfer_img/Image";
  }

  static const char* value(const ::transfer_img::Image_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::transfer_img::Image_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint16 id\n"
"string name\n"
"string msg_type\n"
"string encode_msg\n"
"float64 timestamp\n"
"\n"
;
  }

  static const char* value(const ::transfer_img::Image_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::transfer_img::Image_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.name);
      stream.next(m.msg_type);
      stream.next(m.encode_msg);
      stream.next(m.timestamp);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Image_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::transfer_img::Image_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::transfer_img::Image_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.id);
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.name);
    s << indent << "msg_type: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.msg_type);
    s << indent << "encode_msg: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.encode_msg);
    s << indent << "timestamp: ";
    Printer<double>::stream(s, indent + "  ", v.timestamp);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TRANSFER_IMG_MESSAGE_IMAGE_H
