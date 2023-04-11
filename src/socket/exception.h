#ifndef UDP_EXCEPTION_H
#define UDP_EXCEPTION_H
#include <stdexcept>

namespace udp {

class ConnectionException : public std::runtime_error {
 public:
  ConnectionException(const int error_code)
      : std::runtime_error(std::format("Error code {}", error_code)) {}
};

class UnableToReceiveException : public ConnectionException {
 public:
  UnableToReceiveException(const int error_code)
      : ConnectionException(error_code) {}
};

}  // namespace udp
#endif  // UDP_EXCEPTION_H