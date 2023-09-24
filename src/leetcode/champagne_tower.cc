#ifndef LEETCODE_CHAMPAGNE_TOWER_H
#define LEETCODE_CHAMPAGNE_TOWER_H
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
  double champagneTower(int poured, int query_row, int query_glass) {
    debug("champagne tower\n");
    return 42.0;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CHAMPAGNE_TOWER_H
