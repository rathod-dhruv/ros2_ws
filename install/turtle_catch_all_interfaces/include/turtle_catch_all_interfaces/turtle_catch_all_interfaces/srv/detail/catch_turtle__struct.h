// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_catch_all_interfaces:srv/CatchTurtle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "turtle_catch_all_interfaces/srv/catch_turtle.h"


#ifndef TURTLE_CATCH_ALL_INTERFACES__SRV__DETAIL__CATCH_TURTLE__STRUCT_H_
#define TURTLE_CATCH_ALL_INTERFACES__SRV__DETAIL__CATCH_TURTLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CatchTurtle in the package turtle_catch_all_interfaces.
typedef struct turtle_catch_all_interfaces__srv__CatchTurtle_Request
{
  rosidl_runtime_c__String name;
} turtle_catch_all_interfaces__srv__CatchTurtle_Request;

// Struct for a sequence of turtle_catch_all_interfaces__srv__CatchTurtle_Request.
typedef struct turtle_catch_all_interfaces__srv__CatchTurtle_Request__Sequence
{
  turtle_catch_all_interfaces__srv__CatchTurtle_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_catch_all_interfaces__srv__CatchTurtle_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/CatchTurtle in the package turtle_catch_all_interfaces.
typedef struct turtle_catch_all_interfaces__srv__CatchTurtle_Response
{
  bool success;
} turtle_catch_all_interfaces__srv__CatchTurtle_Response;

// Struct for a sequence of turtle_catch_all_interfaces__srv__CatchTurtle_Response.
typedef struct turtle_catch_all_interfaces__srv__CatchTurtle_Response__Sequence
{
  turtle_catch_all_interfaces__srv__CatchTurtle_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_catch_all_interfaces__srv__CatchTurtle_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  turtle_catch_all_interfaces__srv__CatchTurtle_Event__request__MAX_SIZE = 1
};
// response
enum
{
  turtle_catch_all_interfaces__srv__CatchTurtle_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/CatchTurtle in the package turtle_catch_all_interfaces.
typedef struct turtle_catch_all_interfaces__srv__CatchTurtle_Event
{
  service_msgs__msg__ServiceEventInfo info;
  turtle_catch_all_interfaces__srv__CatchTurtle_Request__Sequence request;
  turtle_catch_all_interfaces__srv__CatchTurtle_Response__Sequence response;
} turtle_catch_all_interfaces__srv__CatchTurtle_Event;

// Struct for a sequence of turtle_catch_all_interfaces__srv__CatchTurtle_Event.
typedef struct turtle_catch_all_interfaces__srv__CatchTurtle_Event__Sequence
{
  turtle_catch_all_interfaces__srv__CatchTurtle_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_catch_all_interfaces__srv__CatchTurtle_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_CATCH_ALL_INTERFACES__SRV__DETAIL__CATCH_TURTLE__STRUCT_H_
