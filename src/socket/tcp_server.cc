#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include "../util/log.h"

namespace tcp {

void server(char* port) {
  util::debug("Start server on port {} \n", port);

  WSADATA wsaData;
  int iResult;
  SOCKET ListenSocket = INVALID_SOCKET;
  SOCKET ClientSocket = INVALID_SOCKET;

  struct addrinfo *result = nullptr, hints;

  int iSendResult;
  char recvbuf[512];
  int recvbuflen = 512;

  // Initialize Winsock
  iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (iResult != 0) {
    throw std::runtime_error("Unalbe to init socket: " + iResult);
  }

  ZeroMemory(&hints, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  hints.ai_flags = AI_PASSIVE;

  // Resolve the local address and port to be used by the server
  iResult = getaddrinfo(NULL, port, &hints, &result);
  if (iResult != 0) {
    WSACleanup();
    throw std::runtime_error("getaddrinfo failed: " + iResult);
  }

  // Create a SOCKET for the server to listen for client connections
  ListenSocket =
      socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (ListenSocket == INVALID_SOCKET) {
    freeaddrinfo(result);
    WSACleanup();
    throw std::runtime_error("Error at socket(): " + WSAGetLastError());
  }

  // Setup the TCP listening socket
  iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
  if (iResult == SOCKET_ERROR) {
    freeaddrinfo(result);
    closesocket(ListenSocket);
    WSACleanup();
    throw std::runtime_error("bind failed with error: " + WSAGetLastError());
  }

  freeaddrinfo(result);

  if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
    closesocket(ListenSocket);
    WSACleanup();
    throw std::runtime_error("Listen failed with error: " + WSAGetLastError());
  }

  // Accept a client socket
  ClientSocket = accept(ListenSocket, NULL, NULL);
  if (ClientSocket == INVALID_SOCKET) {
    closesocket(ListenSocket);
    WSACleanup();
    throw std::runtime_error("accept failed with error: " + WSAGetLastError());
  }

  // No longer need server socket
  closesocket(ListenSocket);

  // Receive until the peer shuts down the connection
  do {
    iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
    if (iResult > 0) {
      util::debug("Received {} bytes\n", iResult);

      // Echo the buffer back to the sender
      iSendResult = send(ClientSocket, recvbuf, iResult, 0);
      if (iSendResult == SOCKET_ERROR) {
        closesocket(ClientSocket);
        WSACleanup();
        throw std::runtime_error("send failed with error: " +
                                 WSAGetLastError());
      }
      util::debug("Sent {} bytes\n", iSendResult);
    } else if (iResult == 0) {
      util::debug("Connection closing...\n");

    } else {
      closesocket(ClientSocket);
      WSACleanup();
      throw std::runtime_error("recv failed with error: " + WSAGetLastError());
    }
  } while (iResult > 0);

  // shutdown the connection since we're done
  iResult = shutdown(ClientSocket, SD_SEND);
  if (iResult == SOCKET_ERROR) {
    closesocket(ClientSocket);
    WSACleanup();
    throw std::runtime_error("shutdown failed with error " + WSAGetLastError());
  }

  // cleanup
  closesocket(ClientSocket);
  WSACleanup();
}

}  // namespace tcp
