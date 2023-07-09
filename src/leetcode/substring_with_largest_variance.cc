#ifndef LEETCODE_SUBSTRING_WITH_LARGEST_VARIANCE_H
#define LEETCODE_SUBSTRING_WITH_LARGEST_VARIANCE_H
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
  int largestVariance(string s) {
    debug("another hard tack\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SUBSTRING_WITH_LARGEST_VARIANCE_H
