#ifndef LEETCODE_NEAREST_EXIT_FROM_ENTRANCE_IN_MAZE_H
#define LEETCODE_NEAREST_EXIT_FROM_ENTRANCE_IN_MAZE_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

using Coord = std::pair<int, int>;
class Solution {
  std::vector<Coord> dirs_;

 public:
  Solution() : dirs_({{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size(), n = maze[0].size();
    std::queue<std::pair<int, int>> queue;
    maze[entrance[0]][entrance[1]] = '+';
    queue.emplace(entrance[0], entrance[1]);
    int dis = 0;
    while (!queue.empty()) {
      int size = queue.size();
      while (size > 0) {
        auto [y, x] = queue.front();
        queue.pop();
        --size;
        for (const auto& dir : dirs_) {
          auto row = y + dir.first;
          auto col = x + dir.second;

          if (row < 0 || row == m) continue;
          if (col < 0 || col == n) continue;
          if (maze[row][col] == '+') continue;

          if (row == 0 || col == 0 || row == (m - 1) || col == (n - 1))
            return dis + 1;

          maze[row][col] = '+';
          queue.emplace(row, col);
        }
      }
      ++dis;
    }
    return -1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NEAREST_EXIT_FROM_ENTRANCE_IN_MAZE_H
