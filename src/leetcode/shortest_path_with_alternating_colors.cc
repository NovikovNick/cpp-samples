#ifndef LEETCODE_SHORTEST_PATH_WITH_ALTERNATING_COLORS_H
#define LEETCODE_SHORTEST_PATH_WITH_ALTERNATING_COLORS_H
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
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                       vector<vector<int>>& blueEdges) {
    std::vector<std::vector<int>> red_adj(n), blue_adj(n);
    for (const auto& edge : redEdges) red_adj[edge[0]].push_back(edge[1]);
    for (const auto& edge : blueEdges) blue_adj[edge[0]].push_back(edge[1]);

    std::vector<bool> red_visited(n, false), blue_visited(n, false);

    std::vector<int> res(n, -1);
    std::queue<std::pair<int, bool>> queue;
    int steps = 0;

    blue_visited[0] = red_visited[0] = true;
    res[0] = steps;
    queue.push({0, true});
    queue.push({0, false});
    ++steps;
    do {
      int size = queue.size();
      while (--size >= 0) {
        auto [curr, prev_red_path] = queue.front();
        queue.pop();

        if (prev_red_path) {
          for (auto adj : blue_adj[curr]) {
            if (!blue_visited[adj]) queue.push({adj, false});
            blue_visited[adj] = true;
            res[adj] = res[adj] == -1 ? steps : std::min(res[adj], steps);
          }
        } else {
          for (auto adj : red_adj[curr]) {
            if (!red_visited[adj]) queue.push({adj, true});
            red_visited[adj] = true;
            res[adj] = res[adj] == -1 ? steps : std::min(res[adj], steps);
          }
        }
      }
      ++steps;
    } while (!queue.empty());
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SHORTEST_PATH_WITH_ALTERNATING_COLORS_H
