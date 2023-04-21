#ifndef LEETCODE_PROFITABLE_SCHEMES_H
#define LEETCODE_PROFITABLE_SCHEMES_H
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
  int profitableSchemes(int n, int minProfit, vector<int>& group,
                        vector<int>& profit) {
    int m = group.size();

    int res = 0;

    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < m; ++i) {
      if (group[i] <= n) pairs.emplace_back(group[i], profit[i]);
    }

    std::sort(pairs.begin(), pairs.end());
    int sum_group = 0;
    int sum_profit = 0;
    for (int i = 0; i < pairs.size(); ++i) {
      int cur_group = sum_group += pairs[i].first;
      int cur_profit = sum_profit += pairs[i].second;
      debug("i = {}\n", i);
      if (cur_profit >= minProfit) ++res;

      for (int k = 0; k <= i; ++k) {
        for (int j = pairs.size() - 1; j >= i; --j) {
          debug("i = {}, k = {}, j = {}\n", i, k, j);
          auto& [j_group, j_profit] = pairs[j];
          if (cur_group + j_group <= n && cur_profit + j_profit >= minProfit) {
            ++res;
          }
        }
        cur_group -= pairs[k].first;
        cur_profit -= pairs[k].second;
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PROFITABLE_SCHEMES_H
