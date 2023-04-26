#ifndef LEETCODE_ADD_DIGITS_H
#define LEETCODE_ADD_DIGITS_H
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
  int addDigits(int num) {
    while (num >= 10) {
      int sum = num % 10;
      while (num /= 10) sum += num % 10;
      num = sum;
    }
    return num;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ADD_DIGITS_H
