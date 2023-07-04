#ifndef LEETCODE_SINGLE_NUMBER_II_H
#define LEETCODE_SINGLE_NUMBER_II_H
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
  int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int num : nums) {
      ones = ((ones ^ num) & (~twos));
      twos = ((twos ^ num) & (~ones));
    }
    return ones;  
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SINGLE_NUMBER_II_H
