#ifndef LEETCODE_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_H
#define LEETCODE_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_H
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
  int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n - 2] != nums[n - 1]) return nums[n - 1];

    int low = 1, mid, high = n - 2;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (nums[mid - 1] == nums[mid]) {
        if (mid % 2 == 0) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else if (nums[mid] == nums[mid + 1]) {
        if (mid % 2 == 0) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      } else {
        return nums[mid];
      }
    }
    return nums[0];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SINGLE_ELEMENT_IN_A_SORTED_ARRAY_H
