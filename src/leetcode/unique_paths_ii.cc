#ifndef LEETCODE_UNIQUE_PATHS_II_H
#define LEETCODE_UNIQUE_PATHS_II_H
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
  int unique_path_count = 0;
  std::vector<std::pair<int, int>> dirs{{1, 0}, {0, 1}};
  int rows, cols;

 public:
  int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    if (grid[0][0] == 0) dfs(0, 0, grid);
    return unique_path_count;
  }

  void dfs(const int row, const int col, const vector<vector<int>>& grid) {
    if (isTarget(row, col)) {
      ++unique_path_count;
      return;
    }

    for (const auto& [offset_row, offset_col] : dirs) {
      int next_row = row + offset_row;
      int next_col = col + offset_col;

      if (isInBound(next_row, next_col) && grid[next_row][next_col] == 0) {
        dfs(next_row, next_col, grid);
      }
    }
  }

  inline bool isTarget(const int row, const int col) const noexcept {
    return row == rows - 1 && col == cols - 1;
  }

  inline bool isInBound(const int row, const int col) const noexcept {
    return row < rows && col < cols;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_UNIQUE_PATHS_II_H
