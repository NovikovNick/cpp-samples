#ifndef LEETCODE_MAXIMUM_NUMBER_OF_EVENTS_THAT_CAN_BE_ATTENDED_II_H
#define LEETCODE_MAXIMUM_NUMBER_OF_EVENTS_THAT_CAN_BE_ATTENDED_II_H
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
  int maxValue(vector<vector<int>>& events, int k) {
    debug("need to find event overlap\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_NUMBER_OF_EVENTS_THAT_CAN_BE_ATTENDED_II_H
