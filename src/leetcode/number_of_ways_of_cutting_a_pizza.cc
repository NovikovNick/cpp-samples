#ifndef LEETCODE_NUMBER_OF_WAYS_OF_CUTTING_A_PIZZA_H
#define LEETCODE_NUMBER_OF_WAYS_OF_CUTTING_A_PIZZA_H
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
  int ways(vector<string>& pizza, int k) {
    debug("Need to cut in {} peaces:\n", k);
    for (const auto& it : pizza) debug("{}\n", it);
    return 1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NUMBER_OF_WAYS_OF_CUTTING_A_PIZZA_H
