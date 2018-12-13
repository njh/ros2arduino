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
 * @file SensorState.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */
#ifndef _TURTLEBOT3_MSGS_SENSOR_STATE_HPP_
#define _TURTLEBOT3_MSGS_SENSOR_STATE_HPP_


#include <topic.hpp>


#include "std_msgs/Header.hpp"

namespace turtlebot3_msgs {


class SensorState : public ros2::Topic<SensorState>
{
public: 
    std_msgs::Header header;
    uint8_t bumper;
    float cliff;
    float sonar;
    float illumination;
    uint8_t led;
    uint8_t button;
    bool torque;
    int32_t left_encoder;
    int32_t right_encoder;
    float battery;

  SensorState():
    Topic("turtlebot3_msgs::msg::dds_::SensorState_", "SensorState"),
    header(),
    bumper(0), cliff(0), sonar(0), illumination(0), led(0), button(0),
    torque(0), left_encoder(0), right_encoder(0), battery(0)
  { 
  }

  bool serialize(void* msg_buf, const SensorState* topic)
  {
    ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
    (void) header.serialize(writer, &topic->header);
    (void) ucdr_serialize_uint8_t(writer, topic->bumper);
    (void) ucdr_serialize_float(writer, topic->cliff);
    (void) ucdr_serialize_float(writer, topic->sonar);
    (void) ucdr_serialize_float(writer, topic->illumination);
    (void) ucdr_serialize_uint8_t(writer, topic->led);
    (void) ucdr_serialize_uint8_t(writer, topic->button);
    (void) ucdr_serialize_bool(writer, topic->torque);
    (void) ucdr_serialize_int32_t(writer, topic->left_encoder);
    (void) ucdr_serialize_int32_t(writer, topic->right_encoder);
    (void) ucdr_serialize_float(writer, topic->battery);

    return !writer->error;
  }

  bool deserialize(void* msg_buf, SensorState* topic)
  {
    ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
    (void) header.deserialize(reader, &topic->header);
    (void) ucdr_deserialize_uint8_t(reader, &topic->bumper);
    (void) ucdr_deserialize_float(reader, &topic->cliff);
    (void) ucdr_deserialize_float(reader, &topic->sonar);
    (void) ucdr_deserialize_float(reader, &topic->illumination);
    (void) ucdr_deserialize_uint8_t(reader, &topic->led);
    (void) ucdr_deserialize_uint8_t(reader, &topic->button);
    (void) ucdr_deserialize_bool(reader, &topic->torque);
    (void) ucdr_deserialize_int32_t(reader, &topic->left_encoder);
    (void) ucdr_deserialize_int32_t(reader, &topic->right_encoder);
    (void) ucdr_deserialize_float(reader, &topic->battery);

    return !reader->error;
  }

  virtual uint32_t size_of_topic(const SensorState* topic, uint32_t size)
  {
    uint32_t previousSize = size;
    size += header.size_of_topic(&topic->header, size);
    size += ucdr_alignment(size, 1) + 1;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 1) + 1;
    size += ucdr_alignment(size, 1) + 1;
    size += ucdr_alignment(size, 1) + 1;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    size += ucdr_alignment(size, 4) + 4;
    
    return size - previousSize;
  }

};

} // namespace turtlebot3_msgs


#endif // _TURTLEBOT3_MSGS_SENSOR_STATE_HPP_
