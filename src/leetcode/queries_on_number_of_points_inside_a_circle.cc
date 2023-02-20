#ifndef LEETCODE_QUERIES_ON_NUMBER_OF_POINTS_INSIDE_A_CIRCLE_H
#define LEETCODE_QUERIES_ON_NUMBER_OF_POINTS_INSIDE_A_CIRCLE_H
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  static bool asc(const vector<int>& lhs, const vector<int>& rhs) {
    return lhs[0] < rhs[0];
  }

  inline float distance(const vector<int>& lhs, const vector<int>& rhs) {
    return std::sqrt(std::pow(lhs[0] - rhs[0], 2) +
                     std::pow(lhs[1] - rhs[1], 2));
  }

  vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& q) {
    std::sort(points.begin(), points.end(), Solution::asc);
    int n = q.size();

    std::vector<int> res(n);
    int radius = 0, val, low, mid, high, low_bound;
    for (int i = 0; i < n; ++i) {
      radius = q[i][2];

      // binary search lower bound
      val = q[i][0] - radius;
      low = 0;
      high = points.size() - 1;
      low_bound = -1;
      while (low <= high) {
        mid = low + (high - low) / 2;
        if (points[mid][0] >= val) {
          high = mid - 1;
          low_bound = mid;
        } else {
          low = mid + 1;
        }
      }

      if (low_bound < 0) continue;

      for (int j = low_bound; j < points.size(); ++j) {
        if (points[j][0] > q[i][0] + radius) break;
        if (distance(points[j], q[i]) <= radius) ++res[i];
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_QUERIES_ON_NUMBER_OF_POINTS_INSIDE_A_CIRCLE_H
