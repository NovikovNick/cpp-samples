#ifndef LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_II_H
#define LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_II_H
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
  bool search(vector<int>& nums, int target) {
    const int pivot = findPivot(nums);
    const int begin = 0;
    const int end = nums.size() - 1;

    return binarySearch(begin, pivot, target, nums) ||
           binarySearch(pivot, end, target, nums);
  }

  int findPivot(const std::vector<int>& nums) {
    int prev = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (prev > nums[i]) return i;
      prev = nums[i];
    }
    return 0;
  }

  bool binarySearch(int begin,
                    int end,
                    const int target,
                    const std::vector<int>& nums) {
    int mid;
    while (begin <= end) {
      mid = begin + (end - begin) / 2;

      if (nums[mid] == target) return true;

      if (nums[mid] < target) {
        begin = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return false;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SEARCH_IN_ROTATED_SORTED_ARRAY_II_H
