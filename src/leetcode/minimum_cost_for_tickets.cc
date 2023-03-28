#ifndef LEETCODE_MINIMUM_COST_FOR_TICKETS_H
#define LEETCODE_MINIMUM_COST_FOR_TICKETS_H
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
  const static int DAYS = 365;  // 365;
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    std::vector<int> dp(DAYS + 1, INT_MAX);
    dp[0] = 0;

    int day = 0;
    for (int i = 1; i < dp.size(); ++i) {
      if (i == days[day]) {
        dp[i] = std::min(dp[i], dp[i - 1] + costs[0]);
        if (++day >= days.size()) return dp[i];
      } else {
        dp[i] = std::min(dp[i], dp[i - 1]);
      }
      for (int j = i; j < dp.size() && j < i + 7; ++j) {
        dp[j] = std::min(dp[j], dp[i - 1] + costs[1]);
      }

      for (int j = i; j < dp.size() && j < i + 30; ++j) {
        dp[j] = std::min(dp[j], dp[i - 1] + costs[2]);
      }
    }

    return dp[DAYS];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_COST_FOR_TICKETS_H
