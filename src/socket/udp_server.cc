#define BUFLEN 1024

#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include "../util/log.h"

namespace udp {

void server(const uint16_t port) {
  util::debug("[SERVER]: start server {}\n", port);

  int res;
  WSADATA wsa;
  SOCKET listen_socket;
  sockaddr_in server, si_other;

  char buf[BUFLEN];
  int slen = sizeof(si_other), recv_len;

  if ((res = WSAStartup(MAKEWORD(2, 2), &wsa)) != 0)
    throw std::runtime_error("Unalbe to init socket: " + WSAGetLastError());

  if ((listen_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
    throw std::runtime_error("Unalbe to create socket: " + WSAGetLastError());

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);

  if (bind(listen_socket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
    throw std::runtime_error("Unalbe to bind socket: " + WSAGetLastError());

  while (1) {
    util::debug("[SERVER]: Waiting for data...\n");
    fflush(stdout);
    memset(buf, '\0', BUFLEN);

    if ((recv_len = recvfrom(listen_socket, buf, BUFLEN, 0,
                             (sockaddr*)&si_other, &slen)) == SOCKET_ERROR) {
      throw std::runtime_error("Unalbe to receiving: " + WSAGetLastError());
    }

    util::debug("[SERVER]: Received packet from {}:{}\n",
                inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
    util::debug("[SERVER]: Data: {}\n", buf);

    // now reply the client with the same data
    if (sendto(listen_socket, buf, recv_len, 0, (sockaddr*)&si_other, slen) ==
        SOCKET_ERROR) {
      throw std::runtime_error("Unalbe to sent: " + WSAGetLastError());
    }
  }

  closesocket(listen_socket);
  WSACleanup();
}

}  // namespace udp
