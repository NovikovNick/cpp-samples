#ifndef LEETCODE_CHECKING_EXISTENCE_OF_EDGE_LENGTH_LIMITED_PATHS_H
#define LEETCODE_CHECKING_EXISTENCE_OF_EDGE_LENGTH_LIMITED_PATHS_H
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
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edge_list,
                                         vector<vector<int>>& queries) {
    std::vector<bool> res(queries.size(), false);

    std::vector<std::vector<pair<int, int>>> nodes(n);
    for (const auto& edge : edge_list) {
      nodes[edge[0]].emplace_back(edge[1], edge[2]);
      nodes[edge[1]].emplace_back(edge[0], edge[2]);
    }

    for (int i = 0; i < n; ++i) {
      debug("{}: ", i);
      for (const auto& [to, dist] : nodes[i]) debug("[{}, {}], ", to, dist);
      debug("\n");
    }

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CHECKING_EXISTENCE_OF_EDGE_LENGTH_LIMITED_PATHS_H
