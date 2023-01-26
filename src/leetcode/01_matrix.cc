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
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    std::vector<std::vector<int>> res(m, std::vector<int>(n));
    std::vector<bool> visited(m * n, false);

    for (int row = 0; row < m; ++row) {
      for (int col = 0; col < n; ++col) {
        res[row][col] = bfs(row, col, mat, visited);
      }
    }
    return res;
  }

  int bfs(const int row, const int col,
          const std::vector<std::vector<int>>& mat,
          std::vector<bool>& visited) {
    int m = mat.size(), n = mat[0].size();
    std::fill(visited.begin(), visited.end(), false);

    std::queue<std::pair<int, int>> queue;
    queue.push({row, col});

    int res = 0;
    while (!queue.empty()) {
      int size = queue.size();
      while (--size >= 0) {
        auto [x, y] = queue.front();
        queue.pop();

        if (mat[x][y] == 0) return res;
        visited[x * n + y] = true;

        if (x - 1 >= 0 && !visited[(x - 1) * n + y]) queue.push({(x - 1), y});
        if (y - 1 >= 0 && !visited[x * n + (y - 1)]) queue.push({x, (y - 1)});

        if (x + 1 <  m && !visited[(x + 1) * n + y]) queue.push({(x + 1), y});
        if (y + 1 <  n && !visited[x * n + (y + 1)]) queue.push({x, (y + 1)});
      }
      ++res;
    }
    return -1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_01_MATRIX_H
