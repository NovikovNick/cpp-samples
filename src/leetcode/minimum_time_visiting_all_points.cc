#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_MINIMUM_TIME_VISITING_ALL_POINTS_H
#define LEETCODE_MINIMUM_TIME_VISITING_ALL_POINTS_H

namespace leetcode {

using namespace std;

class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int res = 0;
    auto p0 = points.begin(), pN = std::next(p0), last = points.end();
    while (pN != last) {
      auto [x0, x1] = std::minmax((*p0)[0], (*pN)[0]);
      auto [y0, y1] = std::minmax((*p0)[1], (*pN)[1]);
      res += std::max(std::abs(x1 - x0), std::abs(y1 - y0));
      ++p0;
      ++pN;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_TIME_VISITING_ALL_POINTS_H
