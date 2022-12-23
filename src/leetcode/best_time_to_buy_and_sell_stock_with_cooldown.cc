#ifndef LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN_H
#define LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN_H
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
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    std::vector<int> dp(n + 2);
    print(dp);

    for (int i = 2; i < dp.size(); ++i) {
      for (int j = i + 1; j < dp.size(); ++j) {
        dp[j] = std::max(
            dp[j - 1],
            std::max(dp[i - 2] + prices[j - 2] - prices[i - 2], dp[j]));
      }
      print(dp);
    }

    return dp[n + 1];
  }
   
  void print(const std::vector<int>& dp) {
    for (const auto& it : dp) debug("{} ", it);
    debug("\n");
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN_H
