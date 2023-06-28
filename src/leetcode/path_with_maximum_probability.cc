#ifndef LEETCODE_PATH_WITH_MAXIMUM_PROBABILITY_H
#define LEETCODE_PATH_WITH_MAXIMUM_PROBABILITY_H
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

struct Edge {
  int node;
  double probability;
};

class Solution {
 public:
  double maxProbability(int n,
                        vector<vector<int>>& edges,
                        vector<double>& succProb,
                        int start,
                        int end) {
    std::vector<std::vector<Edge>> adjacent(n);
    for (int i = 0; i < edges.size(); ++i) {
      adjacent[edges[i][1]].push_back({edges[i][0], succProb[i]});
      adjacent[edges[i][0]].push_back({edges[i][1], succProb[i]});
    }

    std::vector<bool> visited(n, false);

    auto comparator = [](const Edge& lhs, const Edge& rhs) {
      return lhs.probability < rhs.probability;
    };
    std::priority_queue<Edge, std::vector<Edge>, decltype(comparator)> max_heap(
        comparator);

    max_heap.push({start, 1.0});
    while (!max_heap.empty()) {
      const auto [node, probability] = max_heap.top();
      visited[node] = true;
      max_heap.pop();

      if (node == end) return probability;

      for (const auto& adj: adjacent[node]) {
        if (visited[adj.node]) continue;
        max_heap.push({adj.node, probability * adj.probability});  
      }
    }
    return 0.0;
  }
};
}  // namespace leetcode
#endif  // #define LEETCODE_PATH_WITH_MAXIMUM_PROBABILITY_H
