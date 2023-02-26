#ifndef LEETCODE_EDIT_DISTANCE_H
#define LEETCODE_EDIT_DISTANCE_H
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
  int minDistance(string lhs, string rhs) {
    int rows = rhs.size();
    int cols = lhs.size();
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));

    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        int present = rhs[row] == lhs[col];
        dp[row][col] = present;

        if (col - 1 >= 0)
          dp[row][col] = std::max(dp[row][col - 1], dp[row][col]);

        if (row - 1 >= 0)
          dp[row][col] = std::max(dp[row - 1][col], dp[row][col]);

        if (row - 1 >= 0 && col - 1 >= 0)
          dp[row][col] = std::max(dp[row - 1][col - 1] + present, dp[row][col]);
      }
    }
    print(lhs, rhs, dp);

    int res = 0;
    int index = 0;
    int val = -1;
    int prev = 0;
    debug("  ");
    for (int col = 0; col < cols; ++col) {
      if (dp[rows - 1][col] == prev) {
        debug("  ");
        continue;
      }

      int diff = INT_MAX;
      for (int row = val + 1; row < rows; ++row) {
        if (lhs[col] == rhs[row] && std::abs(row - col) < diff) {
          diff = std::abs(row - col);
          val = row;
        }
      }
      auto d = std::max(val, col);
      res += std::max(val, col) - index;
      index = d + 1;
      debug("{} ", val);
      prev = dp[rows - 1][col];
    }
    debug("\n");
    return res;
  }

  void print(const string& lhs, const string& rhs,
             const std::vector<std::vector<int>>& dp) {
    debug("  ");
    for (const auto ch : lhs) debug("{} ", ch);
    debug("\n");

    for (int i = 0; i < dp.size(); ++i) {
      debug("{} ", rhs[i]);
      for (const auto it : dp[i]) debug("{} ", it);
      debug("\n");
    }
    for (const auto& row : dp) {
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_EDIT_DISTANCE_H
