#ifndef LEETCODE_ALL_PATHS_FROM_SOURCE_TO_TARGET_H
#define LEETCODE_ALL_PATHS_FROM_SOURCE_TO_TARGET_H
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
  using GRAPH = std::vector<std::vector<int>>;
  using PATH = std::vector<int>;

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
  GRAPH allPathsSourceTarget(GRAPH& graph) {
    std::vector<std::vector<int>> res;
    dfs({0}, graph, res);
    return res;
  }

  void dfs(PATH path, const GRAPH& graph, std::vector<PATH>& res) {
    int index = path.back();
    int n = graph.size() - 1;
    for (const auto& adj : graph[index]) {
      PATH next = path;
      next.push_back(adj);

      if (adj == n) {
        res.push_back(next);
      } else {
        dfs(next, graph, res);
      }
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ALL_PATHS_FROM_SOURCE_TO_TARGET_H
