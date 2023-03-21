#ifndef LEETCODE_NUMBER_OF_ZERO_FILLED_SUBARRAYS_H
#define LEETCODE_NUMBER_OF_ZERO_FILLED_SUBARRAYS_H
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
  long long zeroFilledSubarray(vector<int>& nums) {
    long long res = 0;
    int count = 0;
    for (const auto& num : nums) {
      if (num == 0) {
        ++count;
        res += count;
      } else {
        count = 0;
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_ZERO_FILLED_SUBARRAYS_H
