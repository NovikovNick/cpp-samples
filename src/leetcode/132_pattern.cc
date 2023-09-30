#ifndef LEETCODE_132_PATTERN_H
#define LEETCODE_132_PATTERN_H
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
  bool find132pattern(vector<int>& nums) {
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, ", "));
    debug("\n");

    return false;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_132_PATTERN_H
