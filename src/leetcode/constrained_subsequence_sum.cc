#ifndef LEETCODE_CONSTRAINED_SUBSEQUENCE_SUM_H
#define LEETCODE_CONSTRAINED_SUBSEQUENCE_SUM_H
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
  int constrainedSubsetSum(vector<int>& nums, int k) {
    debug("constrainedSubsetSum\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CONSTRAINED_SUBSEQUENCE_SUM_H
