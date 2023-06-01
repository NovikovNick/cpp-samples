#ifndef LEETCODE_SHORTEST_PATH_IN_BINARY_MATRIX_H
#define LEETCODE_SHORTEST_PATH_IN_BINARY_MATRIX_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

struct Cell {
  int row, col, path = 0;

  friend Cell operator+(Cell lhs, const Cell& rhs) {
    lhs.row += rhs.row;
    lhs.col += rhs.col;
    ++lhs.path;
    return lhs;
  }

  friend bool operator==(const Cell& lhs, const Cell& rhs) {
    return lhs.row == rhs.row && lhs.col == rhs.col;
  }
};

struct CellDistanceComparator {
  Cell target;
  CellDistanceComparator(const Cell& target) : target(target){};

  bool operator()(const Cell& lhs, const Cell& rhs) const {
    const auto lhs_dist = distance(lhs, target);
    const auto rhs_dist = distance(rhs, target);
    if (lhs_dist == rhs_dist) return lhs.path > rhs.path;
    return lhs_dist > rhs_dist;
  }

  static float distance(const Cell& lhs, const Cell& rhs) {
    return std::sqrt(std::pow(lhs.row - rhs.row, 2) +
                     std::pow(lhs.col - rhs.col, 2));
  }
};

using PRIORITY_QUEUE =
    std::priority_queue<Cell, std::vector<Cell>, CellDistanceComparator>;

class Solution {
  int n;
  std::vector<Cell> dirs{
      {0, 1}, {1, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 0}, {1, -1}, {-1, 1}};

 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0] == 1) return -1;

    n = grid.size();
    const auto target = Cell{n - 1, n - 1};
    PRIORITY_QUEUE min_heap(CellDistanceComparator{target});

    min_heap.push(Cell{0, 0, 0});

    while (!min_heap.empty()) {
      const auto cell = min_heap.top();
      min_heap.pop();

      if (cell == target) return cell.path + 1;

      grid[cell.row][cell.col] = 1;

      for (const auto dir : dirs) {
        auto next = cell + dir;
        if (inBound(next) && grid[next.row][next.col] != 1) min_heap.push(next);
      }
    }

    return -1;
  }

  inline bool inBound(const Cell& cell) const {
    return cell.row >= 0 && cell.row < n && cell.col >= 0 && cell.col < n;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SHORTEST_PATH_IN_BINARY_MATRIX_H
