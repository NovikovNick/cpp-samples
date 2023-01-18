#ifndef LEETCODE_MAXIMUM_SUM_CIRCULAR_SUBARRAY_H
#define LEETCODE_MAXIMUM_SUM_CIRCULAR_SUBARRAY_H
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
  int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    int sum = nums[0];
    int max_elem_index = 0;
    for (int i = 1; i < n; ++i) {
      sum += nums[i];
      if (nums[i] > nums[max_elem_index]) max_elem_index = i;
    }

    int res = nums[max_elem_index];
    int order_sum = 0;
    int inorder_sum = sum - nums[max_elem_index];
    for (int i = 1; i < n; ++i) {
      res = std::max(res, order_sum += nums[(max_elem_index + i) % n]);
      res = std::max(res, inorder_sum -= nums[(max_elem_index + i) % n]);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_SUM_CIRCULAR_SUBARRAY_H
