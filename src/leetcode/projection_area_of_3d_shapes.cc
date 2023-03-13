#ifndef LEETCODE_PROJECTION_AREA_OF_3D_SHAPES_H
#define LEETCODE_PROJECTION_AREA_OF_3D_SHAPES_H
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
  int projectionArea(vector<vector<int>>& grid) {
    return projectionXY(grid) + projectionZY(grid) + projectionZX(grid);
  }

  int projectionXY(const std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    int res = 0;
    for (int col = 0; col < n; ++col) {
      for (int row = 0; row < n; ++row) {
        if (grid[row][col] > 0) ++res;
      }
    }
    return res;
  }

  int projectionZY(const std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    int res = 0;
    for (int col = 0; col < n; ++col) {
      int max_col = 0;
      for (int row = 0; row < n; ++row) {
        max_col = std::max(max_col, grid[row][col]);
      }
      res += max_col;
    }
    return res;
  }

  int projectionZX(const std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    int res = 0;
    for (int row = 0; row < n; ++row) {
      int max_row = 0;
      for (int col = 0; col < n; ++col) {
        max_row = std::max(max_row, grid[row][col]);
      }
      res += max_row;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PROJECTION_AREA_OF_3D_SHAPES_H
