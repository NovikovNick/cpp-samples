#ifndef LEETCODE_REORDER_ROUTES_TO_MAKE_ALL_PATHS_LEAD_TO_THE_CITY_ZERO_H
#define LEETCODE_REORDER_ROUTES_TO_MAKE_ALL_PATHS_LEAD_TO_THE_CITY_ZERO_H
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
  int n;
  std::vector<std::vector<int>> income, outcome;

 public:
  int minReorder(int N, vector<vector<int>>& connections) {
    n = N;
    income = std::vector<std::vector<int>>(n);
    outcome = std::vector<std::vector<int>>(n);

    for (auto const& connection : connections) {
      outcome[connection[1]].emplace_back(connection[0]);
      income[connection[0]].emplace_back(connection[1]);
    }

    int reordered_road_count = 0;
    dfs(0, -1, reordered_road_count);
    return reordered_road_count;
  }

  void dfs(const int city, const int from, int& reordered_road_count) {
    for (auto const out : outcome[city]) {
      if (from != out) dfs(out, city, reordered_road_count);
    }

    for (auto const in : income[city]) {
      if (from != in) dfs(in, city, ++reordered_road_count);
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REORDER_ROUTES_TO_MAKE_ALL_PATHS_LEAD_TO_THE_CITY_ZERO_H
