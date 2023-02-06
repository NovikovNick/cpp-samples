#ifndef LEETCODE_SHUFFLE_THE_ARRAY_H
#define LEETCODE_SHUFFLE_THE_ARRAY_H
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
  vector<int> shuffle(vector<int>& nums, int n) {
    for (int i = 0; i < n - 1; ++i) {
      std::rotate(nums.begin() + 1 + 2 * i, nums.begin() + n + i,
                  nums.begin() + n + 1 + i);
    }
    return nums;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SHUFFLE_THE_ARRAY_H
