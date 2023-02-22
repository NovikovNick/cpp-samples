#ifndef LEETCODE_CAPACITY_TO_SHIP_PACKAGES_WITHIN_D_DAYS_H
#define LEETCODE_CAPACITY_TO_SHIP_PACKAGES_WITHIN_D_DAYS_H
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
  int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    if (n == 1) return weights[0];

    int max_weight = weights[0], sum = weights[0];
    for (int i = 1; i < n; ++i) {
      max_weight = std::max(max_weight, weights[i]);
      sum += weights[i];
    }

    max_weight = std::max(max_weight, sum / days);

    int curr_weight, curr_day, min_overship, start = 1;
    bool all_shiped = false;
    while (!all_shiped) {
      debug("check {}\n", max_weight);
      curr_weight = weights[0];
      curr_day = 1;
      min_overship = INT_MAX;

      for (int i = start; i < n; ++i) {
        debug(" ==> day: {}, weight: {}\n", curr_day, curr_weight);
        curr_weight += weights[i];

        if (curr_weight > max_weight) {
          min_overship = std::min(min_overship, curr_weight - max_weight);
          ++curr_day;
          if (curr_day > days) {
            max_weight += min_overship;
            break;
          }
          curr_weight = weights[i];
        }
        all_shiped = i == n - 1;
      }
    }

    return max_weight;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CAPACITY_TO_SHIP_PACKAGES_WITHIN_D_DAYS_H
