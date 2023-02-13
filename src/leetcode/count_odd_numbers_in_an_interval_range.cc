#ifndef LEETCODE_COUNT_ODD_NUMBERS_IN_AN_INTERVAL_RANGE_H
#define LEETCODE_COUNT_ODD_NUMBERS_IN_AN_INTERVAL_RANGE_H
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
  int countOdds(int low, int high) {
    return (high - low) / 2 + (high % 2 == 0 && low % 2 == 0 ? 0 : 1);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COUNT_ODD_NUMBERS_IN_AN_INTERVAL_RANGE_H
