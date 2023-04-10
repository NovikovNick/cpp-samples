#ifndef LEETCODE_SURFACE_AREA_OF_3D_SHAPES_H
#define LEETCODE_SURFACE_AREA_OF_3D_SHAPES_H
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
  int surfaceArea(vector<vector<int>>& grid) {
    int n = grid.size();
    int res = 0;
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < n; ++col) {
        if (grid[row][col] == 0) continue;
        res += grid[row][col] * 6 - 2 * (grid[row][col] - 1);
        if (row > 0) res -= std::min(grid[row - 1][col], grid[row][col]) * 2;
        if (col > 0) res -= std::min(grid[row][col - 1], grid[row][col]) * 2;
        debug("{} ", res);
      }
      debug("\n");
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SURFACE_AREA_OF_3D_SHAPES_H
