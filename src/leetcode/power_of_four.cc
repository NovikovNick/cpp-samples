#ifndef LEETCODE_POWER_OF_FOUR_H
#define LEETCODE_POWER_OF_FOUR_H
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
  bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    int64_t base = 1;
    while (base <= n) {
      if (base == n) {
        return true;
      }
      base *= 4;
    }
    return false;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_POWER_OF_FOUR_H
