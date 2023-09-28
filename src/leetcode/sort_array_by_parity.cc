#ifndef LEETCODE_SORT_ARRAY_BY_PARITY_H
#define LEETCODE_SORT_ARRAY_BY_PARITY_H
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
  vector<int> sortArrayByParity(vector<int>& nums) {
    int begin = 0;
    int end = nums.size() - 1;
    while (begin != end) {
      if (nums[begin] % 2 == 0) {
        ++begin;
      } else {
        std::swap(nums[begin], nums[end]);
        --end;
      }
    }
    return nums;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SORT_ARRAY_BY_PARITY_H
