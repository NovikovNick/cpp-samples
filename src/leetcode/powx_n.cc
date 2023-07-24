#ifndef LEETCODE_POWX_N_H
#define LEETCODE_POWX_N_H
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
  double myPow(double x, int n) {
    return std::pow(x, n);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_POWX_N_H
