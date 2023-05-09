#ifndef LEETCODE_SPIRAL_MATRIX_H
#define LEETCODE_SPIRAL_MATRIX_H
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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int n = rows * cols;
    std::vector<int> res(n);
    std::vector<Coord> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int dir_index = 0;
    Coord cursor = {0, 0};
    for (int i = 0; i < n; ++i) {
      auto& val = matrix[cursor.row][cursor.col];
      res[i] = val;
      val = INT_MIN;

      auto [row, col] = cursor + dirs[dir_index];
      if (row < rows && row >= 0 && col < cols && col >= 0 &&
          matrix[row][col] != INT_MIN) {
        cursor.row = row;
        cursor.col = col;
      } else {
        ++dir_index;
        dir_index %= dirs.size();
        cursor = cursor + dirs[dir_index];
      }
    }

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SPIRAL_MATRIX_H
