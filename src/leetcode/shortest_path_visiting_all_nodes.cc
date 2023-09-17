#ifndef LEETCODE_SHORTEST_PATH_VISITING_ALL_NODES_H
#define LEETCODE_SHORTEST_PATH_VISITING_ALL_NODES_H
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
  int shortestPathLength(vector<vector<int>>& graph) {
    debug("find shortest path\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE__H
