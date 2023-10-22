#ifndef LEETCODE_MAXIMUM_SCORE_OF_A_GOOD_SUBARRAY_H
#define LEETCODE_MAXIMUM_SCORE_OF_A_GOOD_SUBARRAY_H
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
  int maximumScore(vector<int>& nums, int k) {
    debug("maximumScore\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_SCORE_OF_A_GOOD_SUBARRAY_H
