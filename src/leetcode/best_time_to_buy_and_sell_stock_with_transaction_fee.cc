#ifndef LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_H
#define LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_H
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
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    for (int i = 0; i < n; ++i) {
      debug("{} ", prices[i]);
    }
    debug("\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_TRANSACTION_FEE_H
