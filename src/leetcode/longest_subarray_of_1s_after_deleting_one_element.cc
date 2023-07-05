#ifndef LEETCODE_LONGEST_SUBARRAY_OF_1S_AFTER_DELETING_ONE_ELEMENT_H
#define LEETCODE_LONGEST_SUBARRAY_OF_1S_AFTER_DELETING_ONE_ELEMENT_H
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
  int longestSubarray(vector<int>& nums) {
    int n = nums.size();

    bool zeroExist = false;
    int res = 0;
    int prev = 0;
    int curr = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        zeroExist = true;
        res = std::max(res, curr + prev);

        prev = curr;
        curr = 0;
      } else {
        ++curr;
      }
    }

    res = zeroExist  //
              ? std::max(res, curr + prev)
              : std::max(res, curr - 1);
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_SUBARRAY_OF_1S_AFTER_DELETING_ONE_ELEMENT_H
