#ifndef LEETCODE_RECTANGLE_AREA_H
#define LEETCODE_RECTANGLE_AREA_H
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

// class Solution {
//  public:
//   int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int
//   bx2,
//                   int by2) {
//     int a_s = (ax2 - ax1) * (ay2 - ay1);
//     int b_s = (bx2 - bx1) * (by2 - by1);
//
//     int x_intersection = intersection(ax1, ax2, bx1, bx2);
//     int y_intersection = intersection(ay1, ay2, by1, by2);
//     int a_s_b_s = x_intersection * y_intersection;
//
//     return a_s + b_s - a_s_b_s;
//   }
//
//   int intersection(int ad1, int ad2, int bd1, int bd2) {
//     if (ad1 > bd1) {
//       std::swap(ad1, bd1);
//       std::swap(ad2, bd2);
//     }
//     return ad2 <= bd1 ? 0 : std::abs(std::min(ad2, bd2) - std::max(ad1,
//     bd1));
//   }
// };

class Solution {
 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                  int by2) {
    int x_overlap = std::min(ax2, bx2) - std::max(ax1, bx1);
    int y_overlap = std::min(ay2, by2) - std::max(ay1, by1);
    int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
    return x_overlap > 0 && y_overlap > 0 ? area - x_overlap * y_overlap : area;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_RECTANGLE_AREA_H
