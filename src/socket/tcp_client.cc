#include <winsock2.h>
#include <ws2tcpip.h>

#include "../util/log.h"

namespace tcp {

void client(char* host, char* port) {
  util::debug("Start client to {}:{}\n", host, port);

  int recvbuflen = 512;
  const char* sendbuf = "Does it works?";
  char recvbuf[512];

  WSADATA ws;
  int iResult;
  SOCKET ConnectSocket = INVALID_SOCKET;

  if (FAILED(WSAStartup(MAKEWORD(2, 2), &ws))) {
    int res = 1;
    res = WSAGetLastError();
    throw std::runtime_error("Unable to create socket");
  } else {
    util::debug("Socket created\n");
  }

  // client
  // 1.
  struct addrinfo *result = NULL, *ptr = NULL, hints;
  ZeroMemory(&hints, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  // 2.
  // Resolve the server address and port
  iResult = getaddrinfo(host, port, &hints, &result);
  if (iResult != 0) {
    WSACleanup();
    throw std::runtime_error("getaddrinfo failed");
  }

  // Attempt to connect to an address until one succeeds
  for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
    if (ConnectSocket == INVALID_SOCKET) {
      freeaddrinfo(result);
      WSACleanup();
      throw std::runtime_error("Error at socket " + WSAGetLastError());
    }
    // Connect to server.
    iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
      closesocket(ConnectSocket);
      ConnectSocket = INVALID_SOCKET;
      continue;
    }
    break;  // break the loop after first success connection
  }

  freeaddrinfo(result);

  if (ConnectSocket == INVALID_SOCKET) {
    WSACleanup();
    throw std::runtime_error("Unable to connect to server!");
  }

  // Send an initial buffer
  iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
  if (iResult == SOCKET_ERROR) {
    closesocket(ConnectSocket);
    WSACleanup();
    throw std::runtime_error("send failed with error: " + WSAGetLastError());
  }

  util::debug("Sent {} bytes\n", iResult);

  // shutdown the connection since no more data will be sent
  iResult = shutdown(ConnectSocket, SD_SEND);
  if (iResult == SOCKET_ERROR) {
    closesocket(ConnectSocket);
    WSACleanup();
    throw std::runtime_error("shutdown failed with error: " +
                             WSAGetLastError());
  }

  // Receive until the peer closes the connection
  do {
    iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
    if (iResult > 0) {
      util::debug("Received {} bytes\n", iResult);
    } else if (iResult == 0) {
      util::debug("Connection closed\n");
    } else {
      util::debug("recv failed with error: {}\n", WSAGetLastError());
    }

  } while (iResult > 0);

  // cleanup
  closesocket(ConnectSocket);
  WSACleanup();
}

}  // namespace tcp
