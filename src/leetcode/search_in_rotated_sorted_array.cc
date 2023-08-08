#ifndef LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_H
#define LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_H
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
  const static int kNotFound = -1;

 public:
  int search(vector<int>& nums, int target) {
    const int begin = 0;
    const int pivot = pivotBinarySearch(nums);
    const int end = nums.size() - 1;

    int res = binarySearch(begin, pivot, target, nums);
    if (res != kNotFound) return res;
    return binarySearch(pivot, end, target, nums);
  }

  int pivotBinarySearch(const std::vector<int>& nums) {
    int left = 0, mid, right = nums.size() - 1;
    if (std::abs(right - left) == 0) return 0;
    if (std::abs(right - left) == 1) return nums[left] > nums[right] ? right : 0;

    while (left <= right) {
      mid = left + (right - left) / 2;

      if (nums[mid] > nums[mid + 1]) return mid + 1;
      if (nums[mid] < nums[mid - 1]) return mid;

      if (nums[mid] > nums[left]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return mid;
  }

  int binarySearch(int left,
                   int right,
                   const int target,
                   const std::vector<int>& nums) {
    int mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target) return mid;
      if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return kNotFound;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_H
