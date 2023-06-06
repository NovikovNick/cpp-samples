#ifndef LEETCODE_CAN_MAKE_ARITHMETIC_PROGRESSION_FROM_SEQUENCE_H
#define LEETCODE_CAN_MAKE_ARITHMETIC_PROGRESSION_FROM_SEQUENCE_H
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
  bool canMakeArithmeticProgression(vector<int>& arr) {
    std::sort(arr.begin(), arr.end());

    const int n = arr.size();
    int diff = arr[1] - arr[0];

    for (int i = 2; i < n; ++i) {
      if ((arr[i] - arr[i - 1]) != diff) return false;
    }

    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CAN_MAKE_ARITHMETIC_PROGRESSION_FROM_SEQUENCE_H
