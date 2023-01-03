#ifndef LEETCODE_MAXIMUM_SUBARRAY_H
#define LEETCODE_MAXIMUM_SUBARRAY_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
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
  int maxSubArray(vector<int>& nums) {
    int sum = nums[0];
    int res = nums[0];
    debug("{:3d} {:3d} {:3d}\n", nums[0], sum, res);

    for (int i = 1; i < nums.size(); i++) {
      sum = max(sum + nums[i], nums[i]);
      res = max(res, sum);
      debug("{:3d} {:3d} {:3d}\n", nums[i], sum, res);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_SUBARRAY_H
