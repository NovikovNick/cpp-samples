#ifndef LEETCODE_FROG_JUMP_H
#define LEETCODE_FROG_JUMP_H
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
  bool canCross(vector<int>& stones) {
    debug("Is frog can cross?\n");
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FROG_JUMP_H
