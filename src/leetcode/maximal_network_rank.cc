#ifndef LEETCODE_MAXIMAL_NETWORK_RANK_H
#define LEETCODE_MAXIMAL_NETWORK_RANK_H
#include <algorithm>
#include <format>
#include <iostream>
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
  std::vector<std::unordered_set<int>> cities;
  std::vector<std::pair<int, int>> ranks;

 public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    {  // fill cities
      cities.resize(n);
      for (const auto& road : roads) {
        cities[road[0]].insert(road[1]);
        cities[road[1]].insert(road[0]);
      }
    }

    {  // fill ranks
      ranks.reserve(n);
      for (int i = 0; i < n; ++i) ranks.emplace_back(cities[i].size(), i);
      std::sort(ranks.rbegin(), ranks.rend());
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        auto [rank1, city1] = ranks[i];
        auto [rank2, city2] = ranks[j];
        int rank = rank1 + rank2 + (isConnected(city1, city2) ? -1 : 0);

        debug("{} ? {} = {}\n", city1, city2, rank);
        res = std::max(res, rank);
      }
    }
    return res;
  }

  inline bool isConnected(const int lhs, const int rhs) const noexcept {
    return cities[lhs].find(rhs) != cities[lhs].end();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMAL_NETWORK_RANK_H
