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
  std::vector<int> res;
  std::vector<int> count;
  std::vector<std::vector<int>> adj;
  int N;

 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    N = n;
    res = std::vector<int>(N);
    count = std::vector<int>(N, 1);
    adj = std::vector<std::vector<int>>(N);

    for (const auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    dfs(0, -1);
    dfs2(0, -1);

    for (const auto& it : count) debug("{}, ", it);
    debug("\n");
    for (const auto& it : res) debug("{}, ", it);
    debug("\n");
    return res;
  }

  void dfs(const int node, const int parent) {
    for (const auto& child : adj[node]) {
      if (child != parent) {
        dfs(child, node);
        count[node] += count[child];
        res[node] += res[child] + count[child];
      }
    }
  }

  void dfs2(const int node, const int parent) {
    for (const auto& child : adj[node]) {
      if (child != parent) {
        res[child] = res[node] - count[child] + N - count[child];
        dfs2(child, node);
      }
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SUM_OF_DISTANCES_IN_TREE_H
