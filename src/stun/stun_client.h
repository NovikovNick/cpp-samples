﻿#ifndef STUN_CLIENT_H
#define STUN_CLIENT_H
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#include "exception.h"

namespace stun {

class StunClient {
  SOCKET s;
  uint16_t local_port_;
  sockaddr_in stun_addr, local_addr;
  char buf[1024];  // RFC-8489: If the path MTU is unknown for UDP, messages
                   // SHOULD be the smaller of 576 bytes

 public:
  StunClient(const uint16_t local_port, const char *stun_host,
             const uint16_t stun_port);
  ~StunClient();
  void sendRequest();
  void waitResponse();
  void connect(const char *remote_host, const uint16_t remote_port);
};
}  // namespace stun
#endif  // STUN_CLIENT_H
