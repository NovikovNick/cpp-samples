#ifndef LEETCODE_LARGEST_COLOR_VALUE_IN_A_DIRECTED_GRAPH_H
#define LEETCODE_LARGEST_COLOR_VALUE_IN_A_DIRECTED_GRAPH_H
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
  std::vector<int> color_count = std::vector<int>(128, 0);
  int max_color_count = 0;

  std::vector<bool> nodes;
  std::vector<std::vector<int>> outcoming;

 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    nodes = std::vector<bool>(n);
    outcoming = std::vector<std::vector<int>>(n);

    std::vector<int> incoming(n, 0);
    for (const auto& edge : edges) {
      if (edge[0] == edge[1]) return -1;  // check self cycle
      outcoming[edge[0]].emplace_back(edge[1]);
      ++incoming[edge[1]];
    }

    for (int i = 0; i < n; ++i) {
      if (incoming[i] == 0 && dfs(i, colors, edges)) return -1;
    }

    return max_color_count == 0 ? -1 : max_color_count;
  }

  // return true if path contains cycle
  bool dfs(const int node, const std::string& colors,
           const std::vector<std::vector<int>>& edges) {
    if (nodes[node]) return true;  // check cycles

    // occupy
    nodes[node] = true;
    ++color_count[colors[node]];

    max_color_count = std::max(max_color_count, color_count[colors[node]]);
    for (const auto next : outcoming[node]) {
      if (dfs(next, colors, edges)) return true;  // check cycles
    }

    // release
    nodes[node] = false;
    --color_count[colors[node]];

    return false;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LARGEST_COLOR_VALUE_IN_A_DIRECTED_GRAPH_H
