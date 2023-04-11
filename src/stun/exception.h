#ifndef STUN_EXCEPTION_H
#define STUN_EXCEPTION_H
#include <format>
#include <stdexcept>

namespace stun {

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

}  // namespace stun
#endif  // STUN_EXCEPTION_H