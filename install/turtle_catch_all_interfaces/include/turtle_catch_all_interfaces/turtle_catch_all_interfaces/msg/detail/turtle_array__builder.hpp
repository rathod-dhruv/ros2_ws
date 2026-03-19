// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_catch_all_interfaces:msg/TurtleArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_catch_all_interfaces/msg/turtle_array.hpp"


#ifndef TURTLE_CATCH_ALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__BUILDER_HPP_
#define TURTLE_CATCH_ALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_catch_all_interfaces/msg/detail/turtle_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_catch_all_interfaces
{

namespace msg
{

namespace builder
{

class Init_TurtleArray_turtles
{
public:
  Init_TurtleArray_turtles()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::turtle_catch_all_interfaces::msg::TurtleArray turtles(::turtle_catch_all_interfaces::msg::TurtleArray::_turtles_type arg)
  {
    msg_.turtles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_catch_all_interfaces::msg::TurtleArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_catch_all_interfaces::msg::TurtleArray>()
{
  return turtle_catch_all_interfaces::msg::builder::Init_TurtleArray_turtles();
}

}  // namespace turtle_catch_all_interfaces

#endif  // TURTLE_CATCH_ALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__BUILDER_HPP_
