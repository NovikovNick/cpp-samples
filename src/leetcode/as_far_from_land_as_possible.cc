#ifndef LEETCODE_AS_FAR_FROM_LAND_AS_POSSIBLE_H
#define LEETCODE_AS_FAR_FROM_LAND_AS_POSSIBLE_H
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
  const static int max = 1e5;

 public:
  int maxDistance(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    print(grid);

    // fst traversal - forward
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        auto& val = grid[row][col];
        if (val == 1) continue;
        if (val == 0) val = max;
        if (col - 1 >= 0) val = std::min(val, grid[row][col - 1]);
        if (row - 1 >= 0) val = std::min(val, grid[row - 1][col]);
        ++val;
      }
    }
    print(grid);

    // snd traversal - backward
    int res = 0;
    for (int row = rows - 1; row >= 0; --row) {
      for (int col = cols - 1; col >= 0; --col) {
        auto& val = grid[row][col];
        if (val == 1) continue;
        if (col - 1 >= 0) val = std::min(val, grid[row][col - 1]);
        if (row - 1 >= 0) val = std::min(val, grid[row - 1][col]);
        if (row + 1 < rows) val = std::min(val, grid[row + 1][col]);
        if (col + 1 < cols) val = std::min(val, grid[row][col + 1]);
        ++val;
        res = std::max(res, val);
      }
    }
    print(grid);
    --res;
    return res - 1 == max ? -1 : res;
  }

  void print(const std::vector<std::vector<int>>& grid) {
    debug("-------\n");
    for (const auto& row : grid) {
      for (const auto col : row) debug("{:5d} ", col);
      debug("\n");
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_AS_FAR_FROM_LAND_AS_POSSIBLE_H
