#ifndef LEETCODE_MATRIX_DIAGONAL_SUM_H
#define LEETCODE_MATRIX_DIAGONAL_SUM_H
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
  int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 1) return mat[0][0];

    int sum = 0;
    for (int i = 0; i < n; ++i) sum += mat[i][i] + mat[i][n - i - 1];
    if (n & 1) sum -= mat[n >> 1][n >> 1];
    return sum;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MATRIX_DIAGONAL_SUM_H
