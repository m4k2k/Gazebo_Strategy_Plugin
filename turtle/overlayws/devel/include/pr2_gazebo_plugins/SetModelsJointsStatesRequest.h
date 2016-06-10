// Generated by gencpp from file pr2_gazebo_plugins/SetModelsJointsStatesRequest.msg
// DO NOT EDIT!


#ifndef PR2_GAZEBO_PLUGINS_MESSAGE_SETMODELSJOINTSSTATESREQUEST_H
#define PR2_GAZEBO_PLUGINS_MESSAGE_SETMODELSJOINTSSTATESREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <pr2_gazebo_plugins/ModelJointsState.h>

namespace pr2_gazebo_plugins
{
template <class ContainerAllocator>
struct SetModelsJointsStatesRequest_
{
  typedef SetModelsJointsStatesRequest_<ContainerAllocator> Type;

  SetModelsJointsStatesRequest_()
    : model_names()
    , model_joints_states()  {
    }
  SetModelsJointsStatesRequest_(const ContainerAllocator& _alloc)
    : model_names(_alloc)
    , model_joints_states(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _model_names_type;
  _model_names_type model_names;

   typedef std::vector< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> >::other >  _model_joints_states_type;
  _model_joints_states_type model_joints_states;




  typedef boost::shared_ptr< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetModelsJointsStatesRequest_

typedef ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<std::allocator<void> > SetModelsJointsStatesRequest;

typedef boost::shared_ptr< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest > SetModelsJointsStatesRequestPtr;
typedef boost::shared_ptr< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest const> SetModelsJointsStatesRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace pr2_gazebo_plugins

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/indigo/share/nav_msgs/cmake/../msg'], 'pr2_gazebo_plugins': ['/home/ubu/Gazebo_Strategy_Plugin/turtle/overlayws/src/pr2_simulator/pr2_gazebo_plugins/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/indigo/share/actionlib_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'pr2_msgs': ['/opt/ros/indigo/share/pr2_msgs/cmake/../msg'], 'diagnostic_msgs': ['/opt/ros/indigo/share/diagnostic_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ecf71b483df7b70447575a8231727200";
  }

  static const char* value(const ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xecf71b483df7b704ULL;
  static const uint64_t static_value2 = 0x47575a8231727200ULL;
};

template<class ContainerAllocator>
struct DataType< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pr2_gazebo_plugins/SetModelsJointsStatesRequest";
  }

  static const char* value(const ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] model_names\n\
pr2_gazebo_plugins/ModelJointsState[] model_joints_states\n\
\n\
================================================================================\n\
MSG: pr2_gazebo_plugins/ModelJointsState\n\
geometry_msgs/Pose[] model_pose                          # set as single element array if user wishes to specify model pose, otherwise, leave empty\n\
string[] joint_names                                     # list of joint names\n\
float64[] joint_positions                                 # list of desired joint positions, should match joint_names\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.model_names);
      stream.next(m.model_joints_states);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct SetModelsJointsStatesRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pr2_gazebo_plugins::SetModelsJointsStatesRequest_<ContainerAllocator>& v)
  {
    s << indent << "model_names[]" << std::endl;
    for (size_t i = 0; i < v.model_names.size(); ++i)
    {
      s << indent << "  model_names[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.model_names[i]);
    }
    s << indent << "model_joints_states[]" << std::endl;
    for (size_t i = 0; i < v.model_joints_states.size(); ++i)
    {
      s << indent << "  model_joints_states[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::pr2_gazebo_plugins::ModelJointsState_<ContainerAllocator> >::stream(s, indent + "    ", v.model_joints_states[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PR2_GAZEBO_PLUGINS_MESSAGE_SETMODELSJOINTSSTATESREQUEST_H
