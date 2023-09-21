#ifndef LEETCODE_MEDIAN_OF_TWO_SORTED_ARRAYS_H
#define LEETCODE_MEDIAN_OF_TWO_SORTED_ARRAYS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <set>
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
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    std::copy(nums1.begin(), nums1.end(), std::back_inserter(nums2));
    std::sort(nums2.begin(), nums2.end());

    if ((m + n) % 2 == 0) {
      auto lhs = (n + m) / 2 - 1;
      auto rhs = (n + m) / 2;
      return (nums2[lhs] + nums2[rhs]) / 2.0;
    } else {
      return nums2[(n + m) / 2];
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MEDIAN_OF_TWO_SORTED_ARRAYS_H
