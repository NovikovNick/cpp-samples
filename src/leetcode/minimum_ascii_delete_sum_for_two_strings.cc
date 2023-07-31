#ifndef LEETCODE_MINIMUM_ASCII_DELETE_SUM_FOR_TWO_STRINGS_H
#define LEETCODE_MINIMUM_ASCII_DELETE_SUM_FOR_TWO_STRINGS_H
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
  int minimumDeleteSum(string s1, string s2) {
    int rows = s1.size();
    int cols = s2.size();


    std::vector<std::vector<int>> dp(rows + 1, std::vector<int>(cols + 1));
    for (int row = 1; row <= rows; ++row) {
      for (int col = 1; col <= cols; ++col) {
        if (s1[row - 1] == s2[col - 1]) {
          dp[row][col] = dp[row][col - 1];
        } else {
          dp[row][col] = dp[row - 1][col - 1] + s2[col];
        }
        dp[row][col] =  s1[row - 1];
        debug("{:5d} ", static_cast<int>(dp[row][col]));
      }
      debug("\n");
    }

    return dp[rows][cols];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_ASCII_DELETE_SUM_FOR_TWO_STRINGS_H
