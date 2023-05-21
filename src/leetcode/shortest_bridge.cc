#ifndef LEETCODE_SHORTEST_BRIDGE_H
#define LEETCODE_SHORTEST_BRIDGE_H
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

using GRID = std::vector<std::vector<int>>;

class Solution {
  int n;
  std::vector<std::pair<int, int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int steps = INT_MIN;

 public:
  int shortestBridge(GRID& grid) {
    n = grid.size();

    markAs(2, grid);

    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < n; ++col) {
        if (grid[row][col] == 2) {
          int next_row, next_col;
          for (const auto [x, y] : dirs) {
            next_row = row + x;
            next_col = col + y;

            if (isInBound(next_row, next_col) && isWater(next_row, next_col, grid)) {
              dfsAndCheck(-1, next_row, next_col, grid);
            }
          }
        }
      }
    }
    return std::abs(steps);
  }

  void markAs(const int mark, GRID& grid) {
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < n; ++col) {
        if (grid[row][col] == 1) {
          dfsAndMarkAs(mark, row, col, grid);
          return;
        }
      }
    }
  }

  void dfsAndCheck(const int mark, const int row, const int col, GRID& grid) {
    grid[row][col] = mark;

    int next_row, next_col;
    for (const auto [x, y] : dirs) {
      next_row = row + x;
      next_col = col + y;

      if (!isInBound(next_row, next_col)) continue;
      if (grid[next_row][next_col] == 1) {
        steps = std::max(mark, steps);
        return;
      }
      if (grid[next_row][next_row] == 0 || grid[next_row][next_row] < mark)
        dfsAndCheck(mark - 1, next_row, next_col, grid);
    }
  }

  void dfsAndMarkAs(const int mark, const int row, const int col, GRID& grid) {
    grid[row][col] = mark;

    int next_row, next_col;
    for (const auto [x, y] : dirs) {
      next_row = row + x;
      next_col = col + y;

      if (isInBound(next_row, next_col) && grid[next_row][next_col] == 1) {
        dfsAndMarkAs(mark, next_row, next_col, grid);
      }
    }
  }

  inline bool isWater(const int row, const int col, const GRID& grid) const {
    return grid[row][col] <= 0;
  }

  inline bool isInBound(const int row, const int col) const {
    return row >= 0 && row < n && col >= 0 && col < n;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SHORTEST_BRIDGE_H
