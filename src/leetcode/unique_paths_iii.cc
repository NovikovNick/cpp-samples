#ifndef LEETCODE_UNIQUE_PATHS_III_H
#define LEETCODE_UNIQUE_PATHS_III_H
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
  using GRID = std::vector<std::vector<int>>;
  int n = 0, m = 0, res = 0;

 public:
  int uniquePathsIII(GRID& grid) {
    n = grid.size();
    m = grid[0].size();
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        if (grid[row][col] == 1) {
          dfs(row, col, grid);
          return res;
        }
      }
    }
    return res;
  }

  void dfs(const int row, const int col, GRID& grid) {
    int val = grid[row][col];
    if (val == 2 && allVisited(grid)) {
      ++res;
      return;
    }
    grid[row][col] = -1;
    print(grid);

    if ((col - 1) >= 0 && grid[row][col - 1] != -1) dfs(row, col - 1, grid);
    if ((col + 1) < m && grid[row][col + 1] != -1) dfs(row, col + 1, grid);
    if ((row - 1) >= 0 && grid[row - 1][col] != -1) dfs(row - 1, col, grid);
    if ((row + 1) < n && grid[row + 1][col] != -1) dfs(row + 1, col, grid);

    grid[row][col] = val;
  }

  bool allVisited(const GRID& grid) {
    for (const auto& row : grid)
      for (const auto& it : row)
        if (it == 0) return false;
    return true;
  }

  void print(const GRID& grid) {
    for (const auto& row : grid) {
      for (const auto& col : row) {
        debug("{:2d} ", col);
      }
      debug("\n");
    }
    debug("\n");
  }
};
}  // namespace leetcode
#endif  // LEETCODE_UNIQUE_PATHS_III_H
