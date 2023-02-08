#ifndef LEETCODE_JUMP_GAME_II_H
#define LEETCODE_JUMP_GAME_II_H
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
  int jump(vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= nums[i] && i + j < n; ++j) {
        dp[i + j] = std::min(dp[i + j], dp[i] + 1);
      }
    }
    return dp[n - 1];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_JUMP_GAME_II_H
