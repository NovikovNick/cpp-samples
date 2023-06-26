#ifndef LEETCODE_TOTAL_COST_TO_HIRE_K_WORKERS_H
#define LEETCODE_TOTAL_COST_TO_HIRE_K_WORKERS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
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
  using PAIR = std::pair<int, int>;
  using MIN_HEAP = std::priority_queue<PAIR, std::vector<PAIR>, std::greater<PAIR>>;

 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    int n = costs.size();
    MIN_HEAP min_heap_left, min_heap_right;
    std::less<PAIR> comp;

    int left_index = 0;
    int right_index = n - 1;
    if (candidates * 2 >= n) {
      for (int i = 0; i < n; ++i) min_heap_left.push({costs[i], i});
    } else {
      while (--candidates >= 0) {
        min_heap_left.push({costs[left_index], left_index});
        ++left_index;

        min_heap_right.push({costs[right_index], right_index});
        --right_index;
      }
    }

    long long totalCost = 0;
    while (--k >= 0) {
      if (!min_heap_left.empty() && !min_heap_right.empty()) {
        debug("Check left or right. ");
        if (comp(min_heap_left.top(), min_heap_right.top())) {

          totalCost += min_heap_left.top().first;
          min_heap_left.pop();

          if (left_index <= right_index) {
            min_heap_left.push({costs[left_index], left_index});
            ++left_index;
          }

        } else {
          totalCost += min_heap_right.top().first;
          min_heap_right.pop();

          if (left_index <= right_index) {
            min_heap_right.push({costs[right_index], right_index});
            --right_index;
          }
        }

      } else if (min_heap_left.empty() && !min_heap_right.empty()) {
        debug("Check right {}. ", min_heap_right.top().first);
        totalCost += min_heap_right.top().first;
        min_heap_right.pop();
      } else if (!min_heap_left.empty() && min_heap_right.empty()) {
        debug("Check left {}. ", min_heap_left.top().first);
        totalCost += min_heap_left.top().first;
        min_heap_left.pop();
      }
      debug("\n");
    }
    return totalCost;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_TOTAL_COST_TO_HIRE_K_WORKERS_H
