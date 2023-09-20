#ifndef LEETCODE_MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H
#define LEETCODE_MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H
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
  int minOperations(vector<int>& nums, int x) {
    debug("find min operations\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_OPERATIONS_TO_REDUCE_X_TO_ZERO_H
