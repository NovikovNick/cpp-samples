#ifndef LEETCODE_NUMBER_OF_LONGEST_INCREASING_SUBSEQUENCE_H
#define LEETCODE_NUMBER_OF_LONGEST_INCREASING_SUBSEQUENCE_H
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
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    debug("need to build tree\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_LONGEST_INCREASING_SUBSEQUENCE_H
