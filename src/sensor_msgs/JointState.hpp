// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


/*! 
 * @file JointState.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */
#ifndef _SENSOR_MSGS_JOINT_STATE_HPP_
#define _SENSOR_MSGS_JOINT_STATE_HPP_


#include <topic.hpp>

#include "std_msgs/Header.hpp"

namespace sensor_msgs {

class JointState : public ros2::Topic<JointState>
{
public: 
    std_msgs::Header header;
    char name[10][32];
    uint32_t name_size;
    double position[10];
    uint32_t position_size;
    double velocity[10];
    uint32_t velocity_size;
    double effort[10];
    uint32_t effort_size;

  JointState():
    Topic("sensor_msgs::msg::dds_::JointState_", "JointState"),
    header(),
    name_size(1), position_size(1), velocity_size(1), effort_size(1)
  { 
    memset(name, 0, sizeof(name));
    memset(position, 0, sizeof(position));
    memset(velocity, 0, sizeof(velocity));
    memset(effort, 0, sizeof(effort));
  }

  bool serialize(void* msg_buf, const JointState* topic)
  {
    ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
    (void) header.serialize(writer, &topic->header);
    
    (void) ucdr_serialize_uint32_t(writer, topic->name_size);
    for(uint32_t i = 0; i < topic->name_size; i++)
    {
      (void) ucdr_serialize_string(writer, topic->name[i]);
    } 

    (void) ucdr_serialize_sequence_double(writer, topic->position, topic->position_size);
    (void) ucdr_serialize_sequence_double(writer, topic->velocity, topic->velocity_size);
    (void) ucdr_serialize_sequence_double(writer, topic->effort, topic->effort_size);

    return !writer->error;
  }

  bool deserialize(void* msg_buf, JointState* topic)
  {
    ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
    uint32_t size_string;

    (void) header.deserialize(reader, &topic->header);
    
    (void) ucdr_deserialize_uint32_t(reader, &size_string);
    for(uint32_t i = 0; i < size_string; i++)
    {
      (void) ucdr_deserialize_string(reader, topic->name[i], sizeof(topic->name[i]));
    }

    (void) ucdr_deserialize_sequence_double(reader, topic->position, sizeof(topic->position)/sizeof(double), &topic->position_size);
    (void) ucdr_deserialize_sequence_double(reader, topic->velocity, sizeof(topic->velocity)/sizeof(double), &topic->velocity_size);
    (void) ucdr_deserialize_sequence_double(reader, topic->effort, sizeof(topic->effort)/sizeof(double), &topic->effort_size);

    return !reader->error;
  }

  virtual uint32_t size_of_topic(const JointState* topic, uint32_t size)
  {
    uint32_t previousSize = size;

    size += header.size_of_topic(&topic->header, size);

    size += ucdr_alignment(size, 4) + 4;
    for(uint32_t i = 0; i < name_size; i++)
    {
      size += ucdr_alignment(size, 4) + 4 + (uint32_t)(strlen(name[i]) + 1);
    }

    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 8) + (topic->position_size * 8);

    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 8) + (topic->velocity_size * 8);

    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 8) + (topic->effort_size * 8);

    return size - previousSize;
  }

};

} // namespace sensor_msgs


#endif // _SENSOR_MSGS_JOINT_STATE_HPP_
