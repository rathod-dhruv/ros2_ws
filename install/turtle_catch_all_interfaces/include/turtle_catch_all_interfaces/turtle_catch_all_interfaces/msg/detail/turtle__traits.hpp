// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_catch_all_interfaces:msg/Turtle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_catch_all_interfaces/msg/turtle.hpp"


#ifndef TURTLE_CATCH_ALL_INTERFACES__MSG__DETAIL__TURTLE__TRAITS_HPP_
#define TURTLE_CATCH_ALL_INTERFACES__MSG__DETAIL__TURTLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_catch_all_interfaces/msg/detail/turtle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtle_catch_all_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Turtle & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Turtle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Turtle & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace turtle_catch_all_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use turtle_catch_all_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_catch_all_interfaces::msg::Turtle & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_catch_all_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_catch_all_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtle_catch_all_interfaces::msg::Turtle & msg)
{
  return turtle_catch_all_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_catch_all_interfaces::msg::Turtle>()
{
  return "turtle_catch_all_interfaces::msg::Turtle";
}

template<>
inline const char * name<turtle_catch_all_interfaces::msg::Turtle>()
{
  return "turtle_catch_all_interfaces/msg/Turtle";
}

template<>
struct has_fixed_size<turtle_catch_all_interfaces::msg::Turtle>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtle_catch_all_interfaces::msg::Turtle>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<turtle_catch_all_interfaces::msg::Turtle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_CATCH_ALL_INTERFACES__MSG__DETAIL__TURTLE__TRAITS_HPP_
