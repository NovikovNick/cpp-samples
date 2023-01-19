#ifndef LEETCODE_SUBARRAY_SUMS_DIVISIBLE_BY_K_H
#define LEETCODE_SUBARRAY_SUMS_DIVISIBLE_BY_K_H
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
  int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    int res = 0;
    int prefix = 0;
    std::vector<int> prefix_group(k);
    prefix_group[0] = 1;
    for (const auto& num : nums) {
      prefix = (prefix + num % k + k) % k;
      res += prefix_group[prefix];
      ++prefix_group[prefix];
    }
    debug("\n");
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SUBARRAY_SUMS_DIVISIBLE_BY_K_H
