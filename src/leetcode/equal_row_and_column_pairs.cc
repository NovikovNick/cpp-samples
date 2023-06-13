#ifndef LEETCODE_EQUAL_ROW_AND_COLUMN_PAIRS_H
#define LEETCODE_EQUAL_ROW_AND_COLUMN_PAIRS_H
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
  int equalPairs(vector<vector<int>>& grid) {
    const int n = grid.size();
    if (n == 1) return 1;

    int equalPairsCount = 0;
    std::vector<int> currentCol(n, 0);
    for (int col = 0; col < n; ++col) {

      for (int row = 0; row < n; ++row) currentCol[row] = grid[row][col];

      for (int row = 0; row < n; ++row) {
        if (currentCol == grid[row]) ++equalPairsCount;
      }
    }
    return equalPairsCount;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_EQUAL_ROW_AND_COLUMN_PAIRS_H
