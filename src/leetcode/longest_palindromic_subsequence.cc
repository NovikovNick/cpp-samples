#ifndef LEETCODE_LONGEST_PALINDROMIC_SUBSEQUENCE_H
#define LEETCODE_LONGEST_PALINDROMIC_SUBSEQUENCE_H
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
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i + 1][j + 1] = (s[i] == s[n - j - 1])
                               ? dp[i][j] + 1
                               : std ::max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
    return dp[n][n];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_PALINDROMIC_SUBSEQUENCE_H
