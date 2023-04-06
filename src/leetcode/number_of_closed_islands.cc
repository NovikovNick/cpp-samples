#ifndef LEETCODE_NUMBER_OF_CLOSED_ISLANDS_H
#define LEETCODE_NUMBER_OF_CLOSED_ISLANDS_H
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
  int rows, cols;

 public:
  Solution() : rows(0), cols(0) {}

  int closedIsland(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    int count = 0;
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (grid[row][col] == 0 && dfs(row, col, grid)) ++count;
        debug("{} ", grid[row][col]);
      }
      debug("\n");
    }
    return count;
  }

  bool dfs(const int row, const int col, std::vector<std::vector<int>>& grid) {
    grid[row][col] = 2;  // visited

    bool is_border = false;

    if (row > 0) {
      if (grid[row - 1][col] == 0 && !dfs(row - 1, col, grid)) is_border = true;
    } else {
      is_border = true;
    }

    if (col > 0) {
      if (grid[row][col - 1] == 0 && !dfs(row, col - 1, grid)) is_border = true;
    } else {
      is_border = true;
    }

    if (row + 1 < rows) {
      if (grid[row + 1][col] == 0 && !dfs(row + 1, col, grid)) is_border = true;
    } else {
      is_border = true;
    }

    if (col + 1 < cols) {
      if (grid[row][col + 1] == 0 && !dfs(row, col + 1, grid)) is_border = true;
    } else {
      is_border = true;
    }

    return !is_border;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_CLOSED_ISLANDS_H
