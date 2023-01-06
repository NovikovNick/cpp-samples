#ifndef LEETCODE_RESHAPE_THE_MATRIX_H
#define LEETCODE_RESHAPE_THE_MATRIX_H
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int n = mat.size(), m = mat[0].size();
    if (n * m != r * c) return mat;

    std::vector<std::vector<int>> res(r, std::vector<int>(c));
    for (int i_row = 0, k, i_col, j_row; i_row < n; ++i_row) {
      for (int j_col = 0; j_col < m; ++j_col) {
        k = i_row * m + j_col;
        j_row = k / c;
        i_col = k % c;
        // debug("i_row={},j_col={},k={},i_col={},j_row={}\n", i_row, j_col, k,
        // i_col, j_row);
        res[j_row][i_col] = mat[i_row][j_col];
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_RESHAPE_THE_MATRIX_H
