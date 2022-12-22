#ifndef LEETCODE_SUM_OF_DISTANCES_IN_TREE_H
#define LEETCODE_SUM_OF_DISTANCES_IN_TREE_H
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
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    std::vector<std::vector<int>> adj(n);
    for (const auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    std::vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      std::vector<bool> seen(n, false);
      seen[i] = true;
      res[i] = dfs(i, adj, seen, 0);
    }

    for (const auto& it : res) debug("{}, ", it);
    debug("\n");
    return res;
  }

  int dfs(const int i, const std::vector<std::vector<int>>& adj,
          std::vector<bool>& seen, const int level) {
    int res = 0;
    for (const auto& neighbor : adj[i]) {
      if (!seen[neighbor]) {
        seen[neighbor] = true;
        res += dfs(neighbor, adj, seen, level + 1);
      }
    }
    return level + res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SUM_OF_DISTANCES_IN_TREE_H
