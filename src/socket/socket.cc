#include <winsock.h>
// #include <ws2tcpip.h>

#include "../util/log.h"

namespace socket_sample {

void foo() {
  WSADATA ws;
  if (FAILED(WSAStartup(MAKEWORD(2, 2), &ws))) {
    int res = 1;
    res = WSAGetLastError();

    util::debug("Socket error\n");
    //...
  } else {
    util::debug("Socket created\n");
  }


  // client
  // 1.
  /*struct addrinfo *result = NULL, *ptr = NULL, hints;
  ZeroMemory(&hints, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;*/
  // 2.

}

}  // namespace socket_sample
