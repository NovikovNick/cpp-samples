#ifndef LEETCODE_MONOTONIC_ARRAY_H
#define LEETCODE_MONOTONIC_ARRAY_H
#include <algorithm>
#include <format>
#include <functional>
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
  bool isMonotonic(vector<int>& nums) {
    return check(
        nums,
        nums[0] > nums[nums.size() - 1]  //
            ? [](int& lhs, int& rhs) { return lhs >= rhs; }
            : [](int& lhs, int& rhs) { return lhs <= rhs; });
    ;
  }

  bool check(std::vector<int>& nums, std::function<bool(int&, int&)> predicate) {
    for (int i = 1; i < nums.size(); ++i) {
      if (!predicate(nums[i - 1], nums[i])) return false;
    }
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MONOTONIC_ARRAY_H
