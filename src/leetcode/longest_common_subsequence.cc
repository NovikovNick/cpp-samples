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
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    debug("{}x{}\n", m, n);

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    
    
    
    debug("   ");
    for (int i = 0; i < n; ++i)
      debug("  {}", text2[i]);
    debug("\n");
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j == 0) debug("  {}", text1[i]);
        debug("{:3d}", dp[i][j]);
      }
      debug("\n");
    }
    return 0;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_COMMON_SUBSEQUENCE_H
