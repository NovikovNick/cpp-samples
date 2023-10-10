#ifndef LEETCODE_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_ARRAY_CONTINUOUS_H
#define LEETCODE_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_ARRAY_CONTINUOUS_H
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
  int minOperations(vector<int>& nums) {
    debug("min operations\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_NUMBER_OF_OPERATIONS_TO_MAKE_ARRAY_CONTINUOUS_H
