#ifndef LEETCODE_FIND_IF_PATH_EXISTS_IN_GRAPH_H
#define LEETCODE_FIND_IF_PATH_EXISTS_IN_GRAPH_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
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
  bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
    // init
    std::vector<std::vector<int>> nodes(n);
    for (const auto& edge : edges) {
      nodes[edge[0]].push_back(edge[1]);
      nodes[edge[1]].push_back(edge[0]);
    }

    // dfs
    std::stack<int> dfs;
    dfs.push(src);
    while (!dfs.empty()) {
      auto node = dfs.top();
      dfs.pop();

      if (node == dst) return true;

      for (const auto& adjacent : nodes[node]) dfs.push(adjacent);
      nodes[node].clear();
    }
    return false;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_IF_PATH_EXISTS_IN_GRAPH_H
