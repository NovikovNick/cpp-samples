#ifndef LEETCODE_SPIRAL_MATRIX_II_H
#define LEETCODE_SPIRAL_MATRIX_II_H
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

struct Coord {
  int row, col;
  Coord operator+(const Coord& c) { return {row + c.row, col + c.col}; }
};

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> res(n, std::vector<int>(n));
    std::vector<Coord> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int size = n * n;
    int dir = 0;
    Coord cursor{0, 0};
    for (int i = 1; i <= size; ++i) {
      res[cursor.row][cursor.col] = i;

      auto [row, col] = cursor + dirs[dir];
      if (row >= 0 && row < n && col >= 0 && col < n && res[row][col] == 0) {
        cursor.row = row;
        cursor.col = col;
      } else {
        ++dir;
        dir %= dirs.size();
        cursor = cursor + dirs[dir];
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SPIRAL_MATRIX_II_H
