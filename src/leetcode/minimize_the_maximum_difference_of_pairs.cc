#ifndef LEETCODE_MINIMIZE_THE_MAXIMUM_DIFFERENCE_OF_PAIRS_H
#define LEETCODE_MINIMIZE_THE_MAXIMUM_DIFFERENCE_OF_PAIRS_H
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
 public:
  int minimizeMax(vector<int>& nums, int p) {
    std::sort(nums.begin(), nums.end());

    if (nums.size() == 1 || p == 0) {
      return 0;
    }

    if (nums.size() == 2) {
      return std::abs(nums[0] - nums[1]);
    }

    std::priority_queue<int> max_heap;
    int prev_index = -1;
    int prev_value = INT_MAX;
    int left, right;
    for (int i = 0; i < nums.size() - 2;) {
      left = std::abs(nums[i] - nums[i + 1]);
      right = std::abs(nums[i + 1] - nums[i + 2]);
      debug("|{} - ({}) -  {} - ({}) - {}|\n", i, left, i + 1, right, i + 2);
      if (left <= right) {
        i += 1;
        max_heap.push(left);
      } else {
        i += 2;
        max_heap.push(right);
      }
      if (max_heap.size() > p) max_heap.pop();
    }

    return max_heap.top();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMIZE_THE_MAXIMUM_DIFFERENCE_OF_PAIRS_H
