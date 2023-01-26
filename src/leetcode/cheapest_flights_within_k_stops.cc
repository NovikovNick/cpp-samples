#ifndef LEETCODE_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_H
#define LEETCODE_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_H
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


class Backtracker {
  int min_cost, max_step;
  std::vector<std::vector<std::pair<int, int>>> out;
  std::vector<std::pair<int, int>> dp;

 public:
  std::vector<bool> visited;
  Backtracker(const int n, const int k,
              const std::vector<std::vector<int>>& flights)
      : min_cost(INT_MAX),
        max_step(k),
        out(std::vector<std::vector<std::pair<int, int>>>(n)),
        dp(std::vector<std::pair<int, int>>(n, {INT_MAX, INT_MAX})),
        visited(std::vector<bool>(n, 0)) {
    for (const auto& flight : flights) {
      out[flight[0]].push_back(std::make_pair(flight[1], flight[2]));
    }
  };

  void backtracking(const int src, const int dst, const int total_cost,
                    const int step) {
    //debug("from {} to {} cost {}\n", src, dst, total_cost);

    dp[src] = std::make_pair(total_cost, step);
    for (const auto& [adj, cost] : out[src]) {
      if (visited[adj]) continue;
      if (adj == dst) {
        min_cost = std::min(min_cost, total_cost + cost);
        continue;
      }
      if (step == max_step) continue;
      if ((total_cost + cost) >= min_cost) continue;

      if (dp[adj].first <= (total_cost + cost) && dp[adj].second <= step)
        continue;

      visited[adj] = true;
      backtracking(adj, dst, total_cost + cost, step + 1);
      visited[adj] = false;
    }
  };

  inline int getMinCost() { return min_cost == INT_MAX ? -1 : min_cost; }
};

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    Backtracker backtracker(n, k, flights);
    backtracker.visited[src] = true;
    backtracker.backtracking(src, dst, 0, 0);
    return backtracker.getMinCost();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CHEAPEST_FLIGHTS_WITHIN_K_STOPS_H
