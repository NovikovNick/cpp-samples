#ifndef LEETCODE_N_TH_TRIBONACCI_NUMBER_H
#define LEETCODE_N_TH_TRIBONACCI_NUMBER_H
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
  int tribonacci(int n) {
    std::vector<int> nums{0, 1, 1};
    if (n <= 2) return nums[n];
    for (int i = 3; i <= n; ++i) {
      std::swap(nums[0], nums[1]);
      std::swap(nums[1], nums[2]);
      nums[2] += nums[0] + nums[1];
    }
    return nums[2];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_N_TH_TRIBONACCI_NUMBER_H
