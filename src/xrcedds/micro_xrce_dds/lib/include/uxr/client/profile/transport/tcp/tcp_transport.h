// Copyright 2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#ifndef _UXR_CLIENT_TCP_TRANSPORT_H_
#define _UXR_CLIENT_TCP_TRANSPORT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "../../../core/communication/communication.h"
#include "../../../config.h"
#include "../../../dll.h"

typedef enum uxrTCPInputBufferState
{
    UXR_TCP_BUFFER_EMPTY,
    UXR_TCP_SIZE_INCOMPLETE,
    UXR_TCP_SIZE_READ,
    UXR_TCP_MESSAGE_INCOMPLETE,
    UXR_TCP_MESSAGE_AVAILABLE

} uxrTCPInputBufferState;

typedef struct uxrTCPInputBuffer
{
    uint8_t buffer[UXR_CONFIG_TCP_TRANSPORT_MTU];
    size_t position;
    uxrTCPInputBufferState state;
    size_t msg_size;

} uxrTCPInputBuffer;

struct uxrTCPPlatform;

typedef struct uxrTCPTransport
{
    uxrTCPInputBuffer input_buffer;
    uxrCommunication comm;
    struct uxrTCPPlatform* platform;

} uxrTCPTransport;

UXRDLLAPI bool uxr_init_tcp_transport(uxrTCPTransport* transport,
                                      struct uxrTCPPlatform* platform,
                                      const char* ip,
                                      uint16_t port);

UXRDLLAPI bool uxr_close_tcp_transport(uxrTCPTransport* transport);

#ifdef __cplusplus
}
#endif

#endif //_UXR_CLIENT_TCP_TRANSPORT_H_
