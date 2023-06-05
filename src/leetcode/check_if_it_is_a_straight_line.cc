#ifndef LEETCODE_CHECK_IF_IT_IS_A_STRAIGHT_LINE_H
#define LEETCODE_CHECK_IF_IT_IS_A_STRAIGHT_LINE_H
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
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    auto onStraightLine = [x1 = coordinates[0][0],
                           x2 = coordinates[1][0],
                           y1 = coordinates[0][1],
                           y2 = coordinates[1][1]](const std::vector<int>& point) {
      const int x = point[0];
      const int y = point[1];
      return ((x - x1) * (y2 - y1) - (x2 - x1) * (y - y1)) == 0;
    };
    return std::all_of(coordinates.begin() + 2, coordinates.end(), onStraightLine);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CHECK_IF_IT_IS_A_STRAIGHT_LINE_H
