#ifndef LEETCODE_MATRIX_CELLS_IN_DISTANCE_ORDER_H
#define LEETCODE_MATRIX_CELLS_IN_DISTANCE_ORDER_H
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

inline int getDistance(const std::vector<int>& cell, const int cr,
                       const int cc) {
  return std::abs(cell[0] - cr) + std::abs(cell[1] - cc);
}

class Solution {
 public:
  
  vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                        int cCenter) {
    std::vector<std::vector<int>> res(rows * cols, std::vector<int>(2));
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        res[rows * col + row][0] = row;
        res[rows * col + row][1] = col;
      }
    }

    auto cmp = [rCenter = rCenter, cCenter = cCenter](
                   const std::vector<int>& lhs, const std::vector<int>& rhs) {
      return getDistance(lhs, rCenter, cCenter) <
             getDistance(rhs, rCenter, cCenter);
    };

    std::sort(res.begin(), res.end(), cmp);
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MATRIX_CELLS_IN_DISTANCE_ORDER_H
