#ifndef LEETCODE_COUNT_SUBARRAYS_WITH_FIXED_BOUNDS_H
#define LEETCODE_COUNT_SUBARRAYS_WITH_FIXED_BOUNDS_H
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
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    if (minK == maxK) {
      int res = 0;
      int count = 0;
      for (const auto& num : nums) {
        if (num == minK) {
          ++count;
        } else {
          res += combination(count);
          count = 0;
        }
      }
      return res + combination(count);
    }

    if (minK > maxK) return 0;

    int res = 0;
    int begin = 0;
    int end = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] >= minK && nums[i] <= maxK) {
        if (begin > end) begin = i;
        end = i;
      } else {
        res += combination(minK, maxK, begin, end, nums);
        end = -1;
      }
    }
    return res + combination(minK, maxK, begin, end, nums);
  }

  int combination(const int num) {
    int res = 0;
    for (int i = 1; i <= num; ++i) res += i;
    return res;
  }

  int combination(const int minK, const int maxK, const int begin,
                  const int end, const std::vector<int>& nums) {
    debug("range from {} to {}\n", begin, end);
    for (int i = begin; i <= end; ++i) {
    
    }
    return 1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COUNT_SUBARRAYS_WITH_FIXED_BOUNDS_H
