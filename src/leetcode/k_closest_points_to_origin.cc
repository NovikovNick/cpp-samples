#ifndef LEETCODE_K_CLOSEST_POINTS_TO_ORIGIN_H
#define LEETCODE_K_CLOSEST_POINTS_TO_ORIGIN_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

using POINT = std::vector<int>;

inline float distance(const POINT& p) {
  return std::sqrt(std::pow((0 - p[0]), 2) + std::pow((0 - p[1]), 2));
}

class Solution {
 public:
  vector<POINT> kClosest(vector<POINT>& points, int k) {
    auto cmp = [](const POINT& lhs, const POINT& rhs) {
      return distance(lhs) < distance(rhs);
    };
    /*if (k == 1) return {*std::min_element(points.begin(), points.end(), cmp)};

    std::priority_queue<POINT, std::vector<POINT>, decltype(cmp)> max_heap(cmp);
    for (const auto& point : points) {
      max_heap.push(point);
      if (max_heap.size() > k) max_heap.pop();
    }

    std::vector<POINT> res(max_heap.size());
    for (int i = 0; !max_heap.empty(); ++i, max_heap.pop()) {
      res[i] = max_heap.top();
    }*/

    
    std::nth_element(points.begin(), points.begin() + k, points.end(), cmp);
    points.resize(k);
    return points;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_K_CLOSEST_POINTS_TO_ORIGIN_H
