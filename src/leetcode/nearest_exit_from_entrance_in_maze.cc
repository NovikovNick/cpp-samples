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

using Coord = std::vector<int>;
using Path = std::pair<Coord, int>;
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
    auto hash = [](const Coord& a) {
      auto h1 = std::hash<int>{}(a[0]);
      auto h2 = std::hash<int>{}(a[1]);
      return h1 == h2 ? h1 : h1 ^ h2;
    };

    auto comp = [](const Path& a, const Path& b) {
      return a.second > b.second;
    };

    // Find pathes
    std::unordered_map<Coord, int, decltype(hash)> pathes(m * n, hash);
    pathes[entrance] = 0;
    std::priority_queue<Path, std::vector<Path>, decltype(comp)> queue(comp);

    queue.push({entrance, 0});
    while (!queue.empty()) {
      auto [coord, dis] = queue.top();
      queue.pop();

      int row = coord[0], col = coord[1];
      bool is_edge = (row == 0 || col == 0 || row == (m - 1) || col == (n - 1));
      if (is_edge && (row != entrance[0] || col != entrance[1])) {
        // debug("Reachable exit [{:2d},{:2d}] with distance {}\n", row, col, dis);
        return dis;
      }

      // debug("Check [{:2d},{:2d}] {} \n", row, col, dis);
      for (const auto& dir : dirs_) {
        Coord adjacement = {coord[0] + dir[0], coord[1] + dir[1]};

        if (adjacement[0] < 0 || adjacement[0] == m) continue;
        if (adjacement[1] < 0 || adjacement[1] == n) continue;
        if (maze[adjacement[0]][adjacement[1]] == '+') continue;

        auto explored = pathes.find(adjacement);
        if (explored == pathes.end() || explored->second > (dis + 1)) {
          pathes[adjacement] = (dis + 1);
          queue.push({adjacement, dis + 1});
        }
      }
    }
    return -1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NEAREST_EXIT_FROM_ENTRANCE_IN_MAZE_H
