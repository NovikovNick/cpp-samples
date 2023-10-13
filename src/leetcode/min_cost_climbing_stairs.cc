#ifndef LEETCODE_MIN_COST_CLIMBING_STAIRS_H
#define LEETCODE_MIN_COST_CLIMBING_STAIRS_H
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
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    for (int i = 2; i < n; ++i) {
      cost[i] += std::min(cost[i - 1], cost[i - 2]);
    }
    return std::min(cost[n - 1], cost[n - 2]);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MIN_COST_CLIMBING_STAIRS_H
