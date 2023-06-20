#ifndef LEETCODE_K_RADIUS_SUBARRAY_AVERAGES_H
#define LEETCODE_K_RADIUS_SUBARRAY_AVERAGES_H
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
  vector<int> getAverages(vector<int>& nums, int k) {
    const int n = nums.size();
    const uint64_t divider = k + k + 1;
    std::vector<int> averages(n, -1);

    if (n < divider) return averages;

    uint64_t sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      // debug("sum = {} ", sum);
      if (i + 1 >= divider) {
        averages[i - k] = sum / divider;
        // debug("average[{}] = {}", i - k, averages[i - k]);
        sum -= nums[i + 1 - divider];
      }
      // debug("\n");
    }
    return averages;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_K_RADIUS_SUBARRAY_AVERAGES_H
