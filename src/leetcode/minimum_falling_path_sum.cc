#ifndef LEETCODE_MINIMUM_FALLING_PATH_SUM_H
#define LEETCODE_MINIMUM_FALLING_PATH_SUM_H
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
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 1) return matrix[0][0];

    int val = 0, res = 100 * 100 + 1;
    for (size_t row = 1; row < n; ++row) {
      for (size_t col = 0; col < n; ++col) {
        val = matrix[row][col];
        matrix[row][col] += matrix[row - 1][col];
        if ((col - 1) < n)
          matrix[row][col] =
              std::min(matrix[row - 1][col - 1] + val, matrix[row][col]);
        if ((col + 1) < n)
          matrix[row][col] =
              std::min(matrix[row - 1][col + 1] + val, matrix[row][col]);

        if (row == (n - 1)) res = std::min(res, matrix[row][col]);
      }
    }

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_FALLING_PATH_SUM_H
