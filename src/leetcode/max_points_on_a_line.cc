#ifndef LEETCODE_MAX_POINTS_ON_A_LINE_H
#define LEETCODE_MAX_POINTS_ON_A_LINE_H
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
  using POINT = std::vector<int>;

 public:
  int maxPoints(vector<POINT>& points) {
    int n = points.size();
    int res = 1;
    int count = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        count = 1;
        for (int k = 0; k < n; ++k) {
          if (k == i || k == j) continue;
          if (onLine(points[i], points[j], points[k])) ++count;
        }
        res = std::max(res, count);
      };
    };
    return res;
  }

  inline bool onLine(POINT& a, POINT& b, POINT& c) {
    return numerator(a, b, c) == denumerator(a, b, c);
  }

  inline double numerator(POINT& a, POINT& b, POINT& c) {
    return (c[0] - a[0]) == 0 || (b[0] - a[0]) == 0
               ? 0
               : (c[0] - a[0]) / static_cast<double>(b[0] - a[0]);
  }
  inline double denumerator(POINT& a, POINT& b, POINT& c) {
    return (c[1] - a[1]) == 0 || (b[1] - a[1]) == 0
               ? 0
               : (c[1] - a[1]) / static_cast<double>(b[1] - a[1]);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAX_POINTS_ON_A_LINE_H
