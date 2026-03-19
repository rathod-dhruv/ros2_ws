// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from turtle_catch_all_interfaces:msg/TurtleArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "turtle_catch_all_interfaces/msg/detail/turtle_array__rosidl_typesupport_introspection_c.h"
#include "turtle_catch_all_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "turtle_catch_all_interfaces/msg/detail/turtle_array__functions.h"
#include "turtle_catch_all_interfaces/msg/detail/turtle_array__struct.h"


// Include directives for member types
// Member `turtles`
#include "turtle_catch_all_interfaces/msg/turtle.h"
// Member `turtles`
#include "turtle_catch_all_interfaces/msg/detail/turtle__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  turtle_catch_all_interfaces__msg__TurtleArray__init(message_memory);
}

void turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_fini_function(void * message_memory)
{
  turtle_catch_all_interfaces__msg__TurtleArray__fini(message_memory);
}

size_t turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__size_function__TurtleArray__turtles(
  const void * untyped_member)
{
  const turtle_catch_all_interfaces__msg__Turtle__Sequence * member =
    (const turtle_catch_all_interfaces__msg__Turtle__Sequence *)(untyped_member);
  return member->size;
}

const void * turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__get_const_function__TurtleArray__turtles(
  const void * untyped_member, size_t index)
{
  const turtle_catch_all_interfaces__msg__Turtle__Sequence * member =
    (const turtle_catch_all_interfaces__msg__Turtle__Sequence *)(untyped_member);
  return &member->data[index];
}

void * turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__get_function__TurtleArray__turtles(
  void * untyped_member, size_t index)
{
  turtle_catch_all_interfaces__msg__Turtle__Sequence * member =
    (turtle_catch_all_interfaces__msg__Turtle__Sequence *)(untyped_member);
  return &member->data[index];
}

void turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__fetch_function__TurtleArray__turtles(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const turtle_catch_all_interfaces__msg__Turtle * item =
    ((const turtle_catch_all_interfaces__msg__Turtle *)
    turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__get_const_function__TurtleArray__turtles(untyped_member, index));
  turtle_catch_all_interfaces__msg__Turtle * value =
    (turtle_catch_all_interfaces__msg__Turtle *)(untyped_value);
  *value = *item;
}

void turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__assign_function__TurtleArray__turtles(
  void * untyped_member, size_t index, const void * untyped_value)
{
  turtle_catch_all_interfaces__msg__Turtle * item =
    ((turtle_catch_all_interfaces__msg__Turtle *)
    turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__get_function__TurtleArray__turtles(untyped_member, index));
  const turtle_catch_all_interfaces__msg__Turtle * value =
    (const turtle_catch_all_interfaces__msg__Turtle *)(untyped_value);
  *item = *value;
}

bool turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__resize_function__TurtleArray__turtles(
  void * untyped_member, size_t size)
{
  turtle_catch_all_interfaces__msg__Turtle__Sequence * member =
    (turtle_catch_all_interfaces__msg__Turtle__Sequence *)(untyped_member);
  turtle_catch_all_interfaces__msg__Turtle__Sequence__fini(member);
  return turtle_catch_all_interfaces__msg__Turtle__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_message_member_array[1] = {
  {
    "turtles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(turtle_catch_all_interfaces__msg__TurtleArray, turtles),  // bytes offset in struct
    NULL,  // default value
    turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__size_function__TurtleArray__turtles,  // size() function pointer
    turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__get_const_function__TurtleArray__turtles,  // get_const(index) function pointer
    turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__get_function__TurtleArray__turtles,  // get(index) function pointer
    turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__fetch_function__TurtleArray__turtles,  // fetch(index, &value) function pointer
    turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__assign_function__TurtleArray__turtles,  // assign(index, value) function pointer
    turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__resize_function__TurtleArray__turtles  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_message_members = {
  "turtle_catch_all_interfaces__msg",  // message namespace
  "TurtleArray",  // message name
  1,  // number of fields
  sizeof(turtle_catch_all_interfaces__msg__TurtleArray),
  false,  // has_any_key_member_
  turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_message_member_array,  // message members
  turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_init_function,  // function to initialize message memory (memory has to be allocated)
  turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_message_type_support_handle = {
  0,
  &turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_message_members,
  get_message_typesupport_handle_function,
  &turtle_catch_all_interfaces__msg__TurtleArray__get_type_hash,
  &turtle_catch_all_interfaces__msg__TurtleArray__get_type_description,
  &turtle_catch_all_interfaces__msg__TurtleArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_turtle_catch_all_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtle_catch_all_interfaces, msg, TurtleArray)() {
  turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtle_catch_all_interfaces, msg, Turtle)();
  if (!turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_message_type_support_handle.typesupport_identifier) {
    turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &turtle_catch_all_interfaces__msg__TurtleArray__rosidl_typesupport_introspection_c__TurtleArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
