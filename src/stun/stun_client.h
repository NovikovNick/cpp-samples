#ifndef STUN_CLIENT_H
#define STUN_CLIENT_H
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

#include "exception.h"

namespace stun {

class StunClient {
  SOCKET s;
  sockaddr_in sin;
  char buf[1024];// RFC-8489: If the path MTU is unknown for UDP, messages SHOULD be the smaller of 576 bytes

 public:
  StunClient(const char *host, uint16_t port);
  ~StunClient();
  void sendRequest();
};
}  // namespace stun
#endif  // STUN_CLIENT_H
