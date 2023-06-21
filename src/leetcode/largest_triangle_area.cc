#ifndef LEETCODE_LARGEST_TRIANGLE_AREA_H
#define LEETCODE_LARGEST_TRIANGLE_AREA_H
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
  double largestTriangleArea(vector<vector<int>>& points) {
    const int n = points.size();
    double area = 0;

    int a, b, c;
    for (int i = 0; i < n; ++i) {
      std::vector<int>& p1 = points[i];
      for (int j = i + 1; j < n; ++j) {
        std::vector<int>& p2 = points[j];
        for (int k = j + 1; k < n; ++k) {
          std::vector<int>& p3 = points[k];
          a = p1[0] * (p2[1] - p3[1]);
          b = p2[0] * (p3[1] - p1[1]);
          c = p3[0] * (p1[1] - p2[1]);
          area = max(area, abs(0.5 * (a + b + c)));

          debug("[{}, {}], [{}, {}], [{}, {}] = {}\n",
                p1[0],
                p1[1],
                p2[0],
                p2[1],
                p3[0],
                p3[1],
                area);
        }
      }
    }
    return area;
  }
};
}  // namespace leetcode
#endif  // LEETCODE__H
