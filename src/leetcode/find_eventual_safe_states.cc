#ifndef LEETCODE_FIND_EVENTUAL_SAFE_STATES_H
#define LEETCODE_FIND_EVENTUAL_SAFE_STATES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
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

class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();

    std::vector<int> res;
    std::unordered_set<int> visited;
    /*for (int i = 0; i < n; ++i) {
      visited.clear();
      if (bfs(i, graph, visited)) res.push_back(i);
    }*/
    bfs(1, graph, visited);
    return res;
  }

  bool bfs(const int i,
           const vector<vector<int>>& graph,
           std::unordered_set<int>& visited) {
    std::queue<int> bfs;
    bfs.push(i);
    while (!bfs.empty()) {
      int size = bfs.size();
      debug("\n");

      while (--size >= 0) {
        const auto node = bfs.front();
        bfs.pop();

        debug("{} ", node);
        if (!visited.insert(node).second) return false;
        for (const auto adj : graph[node]) bfs.push(adj);
      }
    }
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_EVENTUAL_SAFE_STATES_H
