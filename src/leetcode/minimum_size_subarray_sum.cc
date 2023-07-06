#ifndef LEETCODE_minimum_size_subarray_sum_H
#define LEETCODE_MINIMUM_SIZE_SUBARRAY_SUM_H
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
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int sum = 0;
    int lenght = 0;
    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == target) return 1;

      sum += nums[i];
      ++lenght;

      while (sum >= target) {
        res = std::min(res, lenght);
        sum -= nums[left];
        ++left;
        --lenght;
      }
    }
    return res == INT_MAX ? 0 : res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_SIZE_SUBARRAY_SUM_H
