#ifndef LEETCODE_MINIMUM_PATH_SUM_H
#define LEETCODE_MINIMUM_PATH_SUM_H
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
  using Path = std::pair<int, int>;

 public:
  int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    std::vector<int> dp(rows * cols, INT_MAX);
    auto cmp = [&dp = dp, cols = cols](const Path& lhs, const Path& rhs) {
      return dp[lhs.first * cols + lhs.second] >
             dp[rhs.first * cols + rhs.second];
    };
    std::priority_queue<Path, std::vector<Path>, decltype(cmp)> min_heap(cmp);

    min_heap.emplace(0, 0);
    dp[0] = grid[0][0];
    while (!min_heap.empty()) {
      auto [row, col] = min_heap.top();
      if (row == rows - 1 && col == cols - 1) return dp[row * cols + col];
      auto sum = dp[row * cols + col];
      min_heap.pop();

      debug("{} {} {} \n", sum, row, col);
      if (row + 1 < rows && dp[(row + 1) * cols + col] > sum + grid[row + 1][col]) {
        dp[(row + 1) * cols + col] = sum + grid[row + 1][col];
        min_heap.emplace(row + 1, col);
      }

      if (col + 1 < cols && dp[row * cols + col + 1] > sum + grid[row][col + 1]) {
        dp[row * cols + col + 1] = sum + grid[row][col + 1];
        min_heap.emplace(row, col + 1);
      }
    }
    return -1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_PATH_SUM_H
