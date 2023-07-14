#ifndef LEETCODE_LONGEST_ARITHMETIC_SUBSEQUENCE_OF_GIVEN_DIFFERENCE_H
#define LEETCODE_LONGEST_ARITHMETIC_SUBSEQUENCE_OF_GIVEN_DIFFERENCE_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
  int longestSubsequence(vector<int>& arr, int diff) {
    int res = 0;
    std::unordered_map<int, int> dp;
    for (const auto num : arr) res = std::max(res, dp[num] = dp[num - diff] + 1);
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_ARITHMETIC_SUBSEQUENCE_OF_GIVEN_DIFFERENCE_H
