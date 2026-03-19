// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from turtle_catch_all_interfaces:msg/TurtleArray.idl
// generated code does not contain a copyright notice

#include "turtle_catch_all_interfaces/msg/detail/turtle_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_turtle_catch_all_interfaces
const rosidl_type_hash_t *
turtle_catch_all_interfaces__msg__TurtleArray__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x52, 0x0b, 0xae, 0xa9, 0xb2, 0xe8, 0xb6, 0xdb,
      0x88, 0x6d, 0x05, 0xf5, 0x3d, 0xcb, 0xc6, 0x01,
      0x8b, 0xde, 0x27, 0x3e, 0xe0, 0xba, 0x8c, 0xd6,
      0xd2, 0xc5, 0xdb, 0xb2, 0x18, 0xf8, 0xfd, 0x17,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "turtle_catch_all_interfaces/msg/detail/turtle__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t turtle_catch_all_interfaces__msg__Turtle__EXPECTED_HASH = {1, {
    0x1f, 0xdd, 0x8c, 0x79, 0xe4, 0x2e, 0x7e, 0x74,
    0x57, 0x3d, 0xaa, 0x7b, 0x1a, 0x40, 0xec, 0x57,
    0xf3, 0x81, 0x1a, 0xca, 0x54, 0xa1, 0xa7, 0x6d,
    0xc7, 0x86, 0x43, 0x22, 0x9e, 0x3d, 0xe1, 0x35,
  }};
#endif

static char turtle_catch_all_interfaces__msg__TurtleArray__TYPE_NAME[] = "turtle_catch_all_interfaces/msg/TurtleArray";
static char turtle_catch_all_interfaces__msg__Turtle__TYPE_NAME[] = "turtle_catch_all_interfaces/msg/Turtle";

// Define type names, field names, and default values
static char turtle_catch_all_interfaces__msg__TurtleArray__FIELD_NAME__turtles[] = "turtles";

static rosidl_runtime_c__type_description__Field turtle_catch_all_interfaces__msg__TurtleArray__FIELDS[] = {
  {
    {turtle_catch_all_interfaces__msg__TurtleArray__FIELD_NAME__turtles, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {turtle_catch_all_interfaces__msg__Turtle__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription turtle_catch_all_interfaces__msg__TurtleArray__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {turtle_catch_all_interfaces__msg__Turtle__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
turtle_catch_all_interfaces__msg__TurtleArray__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {turtle_catch_all_interfaces__msg__TurtleArray__TYPE_NAME, 43, 43},
      {turtle_catch_all_interfaces__msg__TurtleArray__FIELDS, 1, 1},
    },
    {turtle_catch_all_interfaces__msg__TurtleArray__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&turtle_catch_all_interfaces__msg__Turtle__EXPECTED_HASH, turtle_catch_all_interfaces__msg__Turtle__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = turtle_catch_all_interfaces__msg__Turtle__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "Turtle[] turtles";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
turtle_catch_all_interfaces__msg__TurtleArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {turtle_catch_all_interfaces__msg__TurtleArray__TYPE_NAME, 43, 43},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 16, 16},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
turtle_catch_all_interfaces__msg__TurtleArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *turtle_catch_all_interfaces__msg__TurtleArray__get_individual_type_description_source(NULL),
    sources[1] = *turtle_catch_all_interfaces__msg__Turtle__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
