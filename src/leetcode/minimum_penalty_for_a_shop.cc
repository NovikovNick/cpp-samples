#ifndef LEETCODE_MINIMUM_PENALTY_FOR_A_SHOP_H
#define LEETCODE_MINIMUM_PENALTY_FOR_A_SHOP_H
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
  int bestClosingTime(string customers) {
    int penalty = 0;
    for (const auto log : customers) {
      penalty += log == 'Y' ? 0 : 1;
    }

    int closing_hour = customers.size();
    int min_penalty = penalty;
    for (int hour = customers.size() - 1; hour >= 0; --hour) {
      penalty += customers[hour] == 'Y' ? 1 : -1;
      if (penalty <= min_penalty) {
        closing_hour = hour;
        min_penalty = penalty;
      }
    }
    return closing_hour;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_PENALTY_FOR_A_SHOP_H
