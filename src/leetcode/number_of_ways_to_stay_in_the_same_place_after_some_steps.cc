#ifndef LEETCODE_NUMBER_OF_WAYS_TO_STAY_IN_THE_SAME_PLACE_AFTER_SOME_STEPS_H
#define LEETCODE_NUMBER_OF_WAYS_TO_STAY_IN_THE_SAME_PLACE_AFTER_SOME_STEPS_H
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
  int numWays(int steps, int arrLen) {
    debug("and again hard problem\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_WAYS_TO_STAY_IN_THE_SAME_PLACE_AFTER_SOME_STEPS_H
