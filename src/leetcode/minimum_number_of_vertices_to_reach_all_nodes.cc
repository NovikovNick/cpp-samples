#ifndef LEETCODE_MINIMUM_NUMBER_OF_VERTICES_TO_REACH_ALL_NODES_H
#define LEETCODE_MINIMUM_NUMBER_OF_VERTICES_TO_REACH_ALL_NODES_H
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
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    std::vector<bool> counts(n, true);
    for (const auto& edge : edges) {
      counts[edge[1]] = false;
    }

    std::vector<int> res; 
    for (int i = 0; i < n; ++i) {
      if (counts[i]) res.emplace_back(i);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_NUMBER_OF_VERTICES_TO_REACH_ALL_NODES_H
