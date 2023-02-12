#ifndef LEETCODE_MINIMUM_FUEL_COST_TO_REPORT_TO_THE_CAPITAL_H
#define LEETCODE_MINIMUM_FUEL_COST_TO_REPORT_TO_THE_CAPITAL_H
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
  std::vector<std::vector<int>> cities;
  long long fuel = 0;

 public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    cities.resize(roads.size() + 1);
    for (const auto& road : roads) {
      cities[road[0]].push_back(road[1]);
      cities[road[1]].push_back(road[0]);
    }
    for (auto city : cities[0]) dfs(city, 0, seats);
    return fuel;
  }

  int dfs(const int curr, const int parent, const int seats) {
    int people = 1;
    for (const auto city : cities[curr])
      if (city != parent) people += dfs(city, curr, seats);
    fuel += people / seats + (people % seats == 0 ? 0 : 1);
    return people;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_FUEL_COST_TO_REPORT_TO_THE_CAPITAL_H
