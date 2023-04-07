#ifndef LEETCODE_NUMBER_OF_ENCLAVES_H
#define LEETCODE_NUMBER_OF_ENCLAVES_H
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
  int rows = 0, cols = 0;
  std::vector<std::pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

 public:
  int numEnclaves(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid[0].size();
    int res = 0;
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (grid[row][col] > 0) res += dfs(row, col, grid);
        debug("{} ", grid[row][col]);
      }
      debug("\n");
    }
    return res;
  }

  int dfs(const int row, const int col, std::vector<std::vector<int>>& grid) {
    grid[row][col] = -1; // mark as visited

    int enclaves = 1;
    for (const auto [dir_x, dir_y] : dir) {
      if (outOfBorder(row + dir_x, col + dir_y)) {
        enclaves = 0;
        continue;
      }

      if (grid[row + dir_x][col + dir_y] > 0) { // not water and not visited
        int count = dfs(row + dir_x, col + dir_y, grid);
        enclaves = (count != 0 && enclaves != 0) ? enclaves + count : 0;
      }
    }
    return enclaves;
  }

  inline bool outOfBorder(const int row, const int col) {
    return row < 0 || row >= rows || col < 0 || col >= cols;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_ENCLAVES_H
