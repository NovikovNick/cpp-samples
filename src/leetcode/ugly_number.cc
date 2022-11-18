#ifndef LEETCODE_UGLY_NUMBER_H
#define LEETCODE_UGLY_NUMBER_H
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
  bool isUgly(int n) {
    if (n <= 0) return false;
    while (n % 5 == 0) n /= 5;
    while (n % 3 == 0) n /= 3;
    while (n % 2 == 0) n /= 2;
    return n == 1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE__H
