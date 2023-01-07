#ifndef LEETCODE_SEARCH_A_2D_MATRIX_H
#define LEETCODE_SEARCH_A_2D_MATRIX_H
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
  int m, n, mid, row, col, val;
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    m = matrix.size();
    n = matrix[0].size();
    return binarySearch(0, m * n - 1, target, matrix);
  }

  bool binarySearch(const int left, const int right, const int target,
                    vector<vector<int>>& matrix) {
    mid = left == right ? left : left + (right - left) / 2;
    row = mid / n;
    col = mid % n;
    val = matrix[row][col];

    if (left >= right) return val == target;
    if (val > target) return binarySearch(left, mid - 1, target, matrix);
    if (val < target) return binarySearch(mid + 1, right, target, matrix);
    return true;  // val == target
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SEARCH_A_2D_MATRIX_H
