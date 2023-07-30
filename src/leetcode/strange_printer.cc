#ifndef LEETCODE_STRANGE_PRINTER_H
#define LEETCODE_STRANGE_PRINTER_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class Solution {
 public:
  int strangePrinter(string s) {
    debug("strangePrinter\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_STRANGE_PRINTER_H
