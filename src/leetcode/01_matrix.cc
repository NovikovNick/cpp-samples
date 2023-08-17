#ifndef LEETCODE_01_MATRIX_H
#define LEETCODE_01_MATRIX_H
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

class Solution {
  int rows, cols;

 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    rows = mat.size();
    cols = mat[0].size();

    // std::vector<std::vector<int>> dp(rows, std::vector<int>(cols));

    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        mat[row][col] = topDownMin(row, col, mat);
      }
    }

    for (int row = rows - 1; row >= 0; --row) {
      for (int col = cols - 1; col >= 0; --col) {
        mat[row][col] = downTopMin(row, col, mat);
      }
    }

    return mat;
  }

  inline int topDownMin(const int row,
                        const int col,
                        const std::vector<std::vector<int>>& mat) const noexcept {
    if (mat[row][col] == 0) return 0;
    return std::min(top(row, col, mat), left(row, col, mat));
  }

  inline int downTopMin(const int row,
                        const int col,
                        const std::vector<std::vector<int>>& mat) const noexcept {
    if (mat[row][col] == 0) return 0;
    return std::min(std::min(top(row, col, mat), bottom(row, col, mat)),
                    std::min(left(row, col, mat), right(row, col, mat)));
  }

  inline int top(const int row,
                 const int col,
                 const std::vector<std::vector<int>>& mat) const noexcept {
    return (row > 0 && mat[row - 1][col] != INT_MAX)  //
               ? mat[row - 1][col] + 1
               : INT_MAX;
  }

  inline int left(const int row,
                  const int col,
                  const std::vector<std::vector<int>>& mat) const noexcept {
    return (col > 0 && mat[row][col - 1] != INT_MAX)  //
               ? mat[row][col - 1] + 1
               : INT_MAX;
  }

  inline int bottom(const int row,
                    const int col,
                    const std::vector<std::vector<int>>& mat) const noexcept {
    return (row < rows - 1 && mat[row + 1][col] != INT_MAX)  //
               ? mat[row + 1][col] + 1
               : INT_MAX;
  }

  inline int right(const int row,
                   const int col,
                   const std::vector<std::vector<int>>& mat) const noexcept {
    return (col < cols - 1 && mat[row][col + 1] != INT_MAX)  //
               ? mat[row][col + 1] + 1
               : INT_MAX;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_01_MATRIX_H
