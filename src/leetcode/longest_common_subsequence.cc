#ifndef LEETCODE_LONGEST_COMMON_SUBSEQUENCE_H
#define LEETCODE_LONGEST_COMMON_SUBSEQUENCE_H
#include <algorithm>
#include <format>
#include <iostream>
#include <set>
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int longestCommonSubsequence(string a, string b) {
    int m = a.size(), n = b.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
        if (a[i - 1] != b[j - 1]) dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
      }
    }
    // print(a, b, dp);
    return dp[m][n];
  }

  void print(const std::string& a, const std::string& b,
             std::vector<std::vector<int>>& dp) {
    int m = a.size(), n = b.size();
    debug("      ");
    for (int i = 0; i <= n; ++i) debug("  {}", b[i]);
    debug("\n");
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        if (j == 0) debug("  {}", i > 0 ? a[i - 1] : ' ');
        debug("{:3d}", dp[i][j]);
      }
      debug("\n");
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_COMMON_SUBSEQUENCE_H
