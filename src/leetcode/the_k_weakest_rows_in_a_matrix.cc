#ifndef LEETCODE_THE_K_WEAKEST_ROWS_IN_A_MATRIX_H
#define LEETCODE_THE_K_WEAKEST_ROWS_IN_A_MATRIX_H
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
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int m = mat[0].size();

    std::priority_queue<std::pair<int, int>> max_heap;
    for (int i = 0; i < n; ++i) {
      max_heap.emplace(getCountOne(mat[i]), i);
      if (max_heap.size() > k) {
        max_heap.pop();
      }
    }

    std::vector<int> res(k);
    for (int i = k - 1; i >= 0; --i) {
      res[i] = max_heap.top().second;
      max_heap.pop();
    }
    return res;
  }

  int getCountOne(const std::vector<int>& row) {
    int count = 0;
    for (auto col : row) {
      if (col == 1) {
        ++count;
      } else {
        break;
      }
    }
    return count;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_THE_K_WEAKEST_ROWS_IN_A_MATRIX_H
