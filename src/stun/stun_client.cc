#define BUFLEN 1024
#define DEBUG 1;

#include "stun_client.h"

#include <stdio.h>
#include <stdlib.h>

#include "../util/log.h"
#include "packet.h"

namespace stun {

StunClient::StunClient(const char *host, uint16_t port) {
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

StunClient::~StunClient() {
  if (s != INVALID_SOCKET) {
    closesocket(s);
    WSACleanup();
  }
}

void StunClient::sendRequest() {
  PACKET mp;
  PACKET *m = &mp;
  packet_init(m, buf, BUFLEN);
  stun_write_header(m, STUN_BINDING_METHOD);
  stun_write_footer(m);

  int recv_len, slen = sizeof(sin);

  util::debug("[CLIENT]: sending data: {}\n", buf);
  // now reply the client with the same data
  if (sendto(s, m->buf, m->len, 0, (sockaddr *)&sin, slen) == SOCKET_ERROR) {
    throw ConnectionException(WSAGetLastError());
  }

  memset(buf, '\0', BUFLEN);

  if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (sockaddr *)&sin, &slen)) ==
      SOCKET_ERROR) {
    throw UnableToReceiveException(WSAGetLastError());
  }

  util::debug("[CLIENT]: receive back: {}\n", buf);
}

}  // namespace stun
