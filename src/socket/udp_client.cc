#define BUFLEN 1024

#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include "../util/log.h"
#include "exception.h"

namespace udp {

class UdpClient {
  SOCKET s;
  sockaddr_in sin;
  char buf[1024];

 public:
  UdpClient(const char *host, uint16_t port) {
    WSADATA wsa;
    int res, recv_len, slen = sizeof(sin);

    if ((res = WSAStartup(MAKEWORD(2, 2), &wsa)) != 0)
      throw ConnectionException(WSAGetLastError());

    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
      throw ConnectionException(WSAGetLastError());

    memset((char *)&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.S_un.S_addr = inet_addr(host);

    util::debug("[CLIENT]: create sockeet to port {}\n", port);
  }

  void send(std::string str) {
    int recv_len, slen = sizeof(sin);
    int n = str.length();
    strcpy(buf, str.c_str());

    util::debug("[CLIENT]: sending data: {}\n", buf);
    // now reply the client with the same data
    if (sendto(s, buf, n, 0, (sockaddr *)&sin, slen) == SOCKET_ERROR) {
      throw ConnectionException(WSAGetLastError());
    }

    memset(buf, '\0', BUFLEN);

    if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (sockaddr *)&sin, &slen)) ==
        SOCKET_ERROR) {
        throw UnableToReceiveException(WSAGetLastError());
    }

    util::debug("[CLIENT]: receive back: {}\n", buf);
  }

  ~UdpClient() {
    if (s != INVALID_SOCKET) {
      closesocket(s);
      WSACleanup();
    }
  }
};
}  // namespace udp
