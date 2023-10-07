#ifndef LEETCODE_BUILD_ARRAY_WHERE_YOU_CAN_FIND_THE_MAXIMUM_EXACTLY_K_COMPARISONS_H
#define LEETCODE_BUILD_ARRAY_WHERE_YOU_CAN_FIND_THE_MAXIMUM_EXACTLY_K_COMPARISONS_H
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
  int numOfArrays(int n, int m, int k) {
    debug("nums of arrays\n");
    return 0;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BUILD_ARRAY_WHERE_YOU_CAN_FIND_THE_MAXIMUM_EXACTLY_K_COMPARISONS_H
