#define PORT 9999
#define BUFLEN 1024

#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include "../util/log.h"

namespace udp {

class UdpClient {
  SOCKET s;
  sockaddr_in sin;
  char buf[1024];

 public:
  UdpClient(uint16_t port) {
    WSADATA wsa;
    int res, recv_len, slen = sizeof(sin);

    if ((res = WSAStartup(MAKEWORD(2, 2), &wsa)) != 0)
      throw std::runtime_error("Unalbe to init socket: " + WSAGetLastError());

    if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
      throw std::runtime_error("Unalbe to create socket: " + WSAGetLastError());

    memset((char *)&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
  }

  void send(std::string str) {
    int recv_len, slen = sizeof(sin);
    int n = str.length();
    strcpy(buf, str.c_str());

    // now reply the client with the same data
    if (sendto(s, buf, n, 0, (sockaddr *)&sin, slen) == SOCKET_ERROR) {
      throw std::runtime_error("Unalbe to sent: " + WSAGetLastError());
    }

    memset(buf, '\0', BUFLEN);

    if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (sockaddr *)&sin, &slen)) ==
        SOCKET_ERROR) {
      throw std::runtime_error("Unalbe to receiving: " + WSAGetLastError());
    }

    util::debug("Data: {}\n", buf);
  }

  ~UdpClient() {
    if (s != INVALID_SOCKET) {
      closesocket(s);
      WSACleanup();
    }
  }
};
}  // namespace udp
