#ifndef LEETCODE_CHECK_IF_THERE_IS_A_VALID_PARTITION_FOR_THE_ARRAY_H
#define LEETCODE_CHECK_IF_THERE_IS_A_VALID_PARTITION_FOR_THE_ARRAY_H
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
  bool validPartition(vector<int>& nums) {
    int valid = false;
    int prev_value = nums[0];
    int duplicate_count = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == prev_value) {
        ++duplicate_count;
        valid = true;
      } else {
        if (isValid(i, nums)) {

        }
        prev_value = nums[i];
        duplicate_count = 1;
      }

      debug("{}: {}\n", nums[i], duplicate_count);
    }
    return valid;
  }

  inline bool isValid(const int i, const std::vector<int>& nums) const {
    return i + 1 < nums.size()            //
           && nums[i - 1] + 1 == nums[i]  //
           && nums[i] + 1 == nums[i + 1];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CHECK_IF_THERE_IS_A_VALID_PARTITION_FOR_THE_ARRAY_H
