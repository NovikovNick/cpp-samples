#ifndef LEETCODE_MINIMUM_NUMBER_OF_TAPS_TO_OPEN_TO_WATER_A_GARDEN_H
#define LEETCODE_MINIMUM_NUMBER_OF_TAPS_TO_OPEN_TO_WATER_A_GARDEN_H
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
  int minTaps(int n, vector<int>& ranges) {
    debug("minTaps\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_NUMBER_OF_TAPS_TO_OPEN_TO_WATER_A_GARDEN_H
