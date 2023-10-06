#ifndef LEETCODE_INTEGER_BREAK_H
#define LEETCODE_INTEGER_BREAK_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <array>

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
  int integerBreak(int n) {
    std::array<int, 59> dp;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 4;
    dp[5] = 6;
    dp[6] = 9;
    dp[7] = 12;

    for (int i = 8; i <= n; ++i) {
      dp[i] = std::max(dp[i - 2] * 2, dp[i - 3] * 3);
    }

    return dp[n];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_INTEGER_BREAK_H
