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

struct State {
  int profit, stock, waiting_days;

  State(const int profit, const int stock, const int waiting_days)
      : profit(profit), stock(stock), waiting_days(waiting_days) {}

  State buy(const int price) { return State(profit, price, waiting_days); };

  State sell(const int price) {
    return State(profit + (price - stock), -1, 0);
  };

  State cooldown() { return State(profit, stock, waiting_days + 1); };

  bool can_buy() { return stock < 0 && waiting_days > 0; }
  bool can_sell() { return stock >= 0; }
};
class Solution {
  std::vector<int> dp;
  int n, profit;

 public:
  int maxProfit(vector<int>& prices) {
    n = prices.size();
    dp = std::vector<int>(n);
    profit = 0;

    dfs(State(0, -1, 1), 0, prices);
    return profit;
  }

  void dfs(State state, const int day, std::vector<int>& prices) {
    if (day >= n) return;

    debug("Day {}. Profit = {}, stock = {}\n", day, state.profit, state.stock);
    if (state.can_buy()) dfs(state.buy(prices[day]), day + 1, prices);
    if (state.can_sell()) {
      auto new_state = state.sell(prices[day]);
      if (dp[day] < new_state.profit) {
        dp[day] = new_state.profit;
        dfs(new_state, day + 1, prices);
        profit = std::max(profit, new_state.profit);
      }
    }
    dfs(state.cooldown(), day + 1, prices);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BEST_TIME_TO_BUY_AND_SELL_STOCK_WITH_COOLDOWN_H
