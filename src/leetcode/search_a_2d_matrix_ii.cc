#ifndef LEETCODE_SEARCH_A_2D_MATRIX_II_H
#define LEETCODE_SEARCH_A_2D_MATRIX_II_H
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
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int row = 0; row < rows; ++row) {
      if (matrix[row][0] <= target && matrix[row][cols - 1] >= target) {
        if (binarySearch(target, matrix[row])) return true;
      }
    }
    return false;
  }

  bool binarySearch(const int target, const vector<int>& row) {
    int left = 0, mid, right = row.size() - 1;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (row[mid] == target) return true;
      if (row[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return false;
  }

  // bruteforce
  /*bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    debug("matrix\n");
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (matrix[row][col] == target) return true;
      }
    }
    return false;
  }*/
};
}  // namespace leetcode
#endif  // LEETCODE_SEARCH_A_2D_MATRIX_II_H
