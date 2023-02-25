#ifndef LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_H
#define LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_H
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

    int res = 0;
    int min = prices[0];
    for (int i = 1; i < n; ++i) {
      min = std::min(min, prices[i]);
      res = std::max(res, prices[i] - min);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_H
