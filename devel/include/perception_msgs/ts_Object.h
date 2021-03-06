// Generated by gencpp from file perception_msgs/ts_Object.msg
// DO NOT EDIT!


#ifndef PERCEPTION_MSGS_MESSAGE_TS_OBJECT_H
#define PERCEPTION_MSGS_MESSAGE_TS_OBJECT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <perception_msgs/ts_3DPose.h>
#include <perception_msgs/ts_Geometry.h>

namespace perception_msgs
{
template <class ContainerAllocator>
struct ts_Object_
{
  typedef ts_Object_<ContainerAllocator> Type;

  ts_Object_()
    : object_id(0)
    , rel_pose()
    , geometry_state(false)
    , geometry()  {
    }
  ts_Object_(const ContainerAllocator& _alloc)
    : object_id(0)
    , rel_pose(_alloc)
    , geometry_state(false)
    , geometry(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _object_id_type;
  _object_id_type object_id;

   typedef  ::perception_msgs::ts_3DPose_<ContainerAllocator>  _rel_pose_type;
  _rel_pose_type rel_pose;

   typedef uint8_t _geometry_state_type;
  _geometry_state_type geometry_state;

   typedef  ::perception_msgs::ts_Geometry_<ContainerAllocator>  _geometry_type;
  _geometry_type geometry;





  typedef boost::shared_ptr< ::perception_msgs::ts_Object_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::perception_msgs::ts_Object_<ContainerAllocator> const> ConstPtr;

}; // struct ts_Object_

typedef ::perception_msgs::ts_Object_<std::allocator<void> > ts_Object;

typedef boost::shared_ptr< ::perception_msgs::ts_Object > ts_ObjectPtr;
typedef boost::shared_ptr< ::perception_msgs::ts_Object const> ts_ObjectConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::perception_msgs::ts_Object_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::perception_msgs::ts_Object_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace perception_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'perception_msgs': ['/home/leiyubiao/dalian/src/tracking/messages/perception_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::perception_msgs::ts_Object_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::perception_msgs::ts_Object_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::perception_msgs::ts_Object_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::perception_msgs::ts_Object_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::perception_msgs::ts_Object_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::perception_msgs::ts_Object_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::perception_msgs::ts_Object_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2fab78d59d066c44e1549d3ee0b45ece";
  }

  static const char* value(const ::perception_msgs::ts_Object_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2fab78d59d066c44ULL;
  static const uint64_t static_value2 = 0xe1549d3ee0b45eceULL;
};

template<class ContainerAllocator>
struct DataType< ::perception_msgs::ts_Object_<ContainerAllocator> >
{
  static const char* value()
  {
    return "perception_msgs/ts_Object";
  }

  static const char* value(const ::perception_msgs::ts_Object_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::perception_msgs::ts_Object_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
int32 object_id\n\
\n\
ts_3DPose rel_pose\n\
\n\
bool geometry_state\n\
ts_Geometry geometry\n\
\n\
================================================================================\n\
MSG: perception_msgs/ts_3DPose\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 phi\n\
float64 theta\n\
float64 psi\n\
\n\
================================================================================\n\
MSG: perception_msgs/ts_Geometry\n\
float64 length\n\
float64 width\n\
float64 height\n\
";
  }

  static const char* value(const ::perception_msgs::ts_Object_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::perception_msgs::ts_Object_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.object_id);
      stream.next(m.rel_pose);
      stream.next(m.geometry_state);
      stream.next(m.geometry);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ts_Object_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::perception_msgs::ts_Object_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::perception_msgs::ts_Object_<ContainerAllocator>& v)
  {
    s << indent << "object_id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.object_id);
    s << indent << "rel_pose: ";
    s << std::endl;
    Printer< ::perception_msgs::ts_3DPose_<ContainerAllocator> >::stream(s, indent + "  ", v.rel_pose);
    s << indent << "geometry_state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.geometry_state);
    s << indent << "geometry: ";
    s << std::endl;
    Printer< ::perception_msgs::ts_Geometry_<ContainerAllocator> >::stream(s, indent + "  ", v.geometry);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PERCEPTION_MSGS_MESSAGE_TS_OBJECT_H
