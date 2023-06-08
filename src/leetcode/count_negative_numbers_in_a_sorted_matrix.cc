#ifndef LEETCODE_COUNT_NEGATIVE_NUMBERS_IN_A_SORTED_MATRIX_H
#define LEETCODE_COUNT_NEGATIVE_NUMBERS_IN_A_SORTED_MATRIX_H
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
  int countNegatives(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    for (int row = 0; row < m; ++row) {
      for (int col = 0; col < n; ++col) debug("{:3d} ", grid[row][col]);
      debug("\n");
    }

    int res = 0;
    for (int row = m - 1; row >= 0 && grid[row][n - 1] < 0; --row) {
      for (int col = n - 1; col >= 0 && grid[row][col] < 0; --col) ++res;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COUNT_NEGATIVE_NUMBERS_IN_A_SORTED_MATRIX_H
