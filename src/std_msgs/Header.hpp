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
 * @file Header.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _STD_MSGS_HEADER_HPP_
#define _STD_MSGS_HEADER_HPP_


#include <topic.hpp>

#include "builtin_interfaces/Time.hpp"

namespace std_msgs {

class Header : public ros2::Topic<Header>
{
public:

  builtin_interfaces::Time stamp;
  char frame_id[64];

  Header():
    Topic("std_msgs::msg::dds_::Header_", "Header"),
    stamp()
  { 
    memset(frame_id, 0, sizeof(frame_id));
  }


  bool serialize(void* msg_buf, const Header* topic)
  {
    ucdrBuffer* writer = (ucdrBuffer*)msg_buf;
    (void) stamp.serialize(writer, &topic->stamp);
    (void) ucdr_serialize_string(writer, topic->frame_id);

    return !writer->error;
  }

  bool deserialize(void* msg_buf, Header* topic)
  {
    ucdrBuffer* reader = (ucdrBuffer*)msg_buf;
    (void) stamp.deserialize(reader, &topic->stamp);
    (void) ucdr_deserialize_string(reader, topic->frame_id, sizeof(topic->frame_id));

    return !reader->error;
  }

  uint32_t size_of_topic(const Header* topic, uint32_t size)
  {
    uint32_t previousSize = size;
    size += stamp.size_of_topic(&topic->stamp, size);
    size += ucdr_alignment(size, 4) + 4 + (uint32_t)(strlen(topic->frame_id) + 1);

    return size - previousSize;
  }
};

} // namespace std_msgs


#endif // _STD_MSGS_HEADER_HPP_
