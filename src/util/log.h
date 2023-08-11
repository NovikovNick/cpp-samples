#ifndef UTIL_LOGGER_H
#define UTIL_LOGGER_H
#include <format>
#include <iostream>

namespace util {

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if defined(DEBUG)
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}
}  // namespace util
#endif  // UTIL_LOGGER_H