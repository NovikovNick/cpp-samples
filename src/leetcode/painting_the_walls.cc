#ifndef LEETCODE_PAINTING_THE_WALLS_H
#define LEETCODE_PAINTING_THE_WALLS_H
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
  int paintWalls(vector<int>& cost, vector<int>& time) {
    debug("paintWalls\n");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PAINTING_THE_WALLS_H
