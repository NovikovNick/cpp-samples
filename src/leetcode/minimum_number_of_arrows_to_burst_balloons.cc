#ifndef LEETCODE_MINIMUM_NUMBER_OF_ARROWS_TO_BURST_BALLOONS_H
#define LEETCODE_MINIMUM_NUMBER_OF_ARROWS_TO_BURST_BALLOONS_H
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
  static bool rightComp(std::vector<int>& a, std::vector<int>& b) {
    return a[1] < b[1];
  }

  int findMinArrowShots(vector<vector<int>>& points) {
    std::sort(points.begin(), points.end(), rightComp);

    int n = points.size();
    int res = 1;
    int prev = points[0][1];
    for (int i = 1; i < n; ++i) {
      if (points[i][0] > prev) {
        ++res;
        prev = points[i][1];
      }
    }

    for (const auto& point : points)
      debug("{:3d} - {:3d}\n", point[0], point[1]);
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_NUMBER_OF_ARROWS_TO_BURST_BALLOONS_H
