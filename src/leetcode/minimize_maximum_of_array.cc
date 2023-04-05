#ifndef LEETCODE_MINIMIZE_MAXIMUM_OF_ARRAY_H
#define LEETCODE_MINIMIZE_MAXIMUM_OF_ARRAY_H
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
  int minimizeArrayValue(vector<int>& nums) {
    return nums[0];
  }

  int bruteforce(vector<int>& nums) {
    int diff;
    int max = *std::max_element(nums.begin(), nums.end());
    while (nums[0] != max) {
      max = nums[0];
      for (int i = nums.size() - 1; i > 0; --i) {
        if (nums[i] > nums[i - 1]) {
          diff = std::ceil((nums[i] - nums[i - 1]) / 2.0);
          nums[i] -= diff;
          nums[i - 1] += diff;
        };
        max = std::max(max, nums[i - 1]);
      }
    }
    return nums[0];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMIZE_MAXIMUM_OF_ARRAY_H
