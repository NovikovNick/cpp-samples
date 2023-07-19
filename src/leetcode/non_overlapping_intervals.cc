#ifndef LEETCODE_NON_OVERLAPPING_INTERVALS_H
#define LEETCODE_NON_OVERLAPPING_INTERVALS_H
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
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), Solution::compare);
    Solution::print(intervals);

    int res = 0;
    int min = intervals[0][0], max = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] >= max) {
        min = intervals[i][0];
        max = intervals[i][1];
      } else {
        ++res;
      }
    }
    return res;
  }

  static bool compare(const std::vector<int>& lhs, const std::vector<int>& rhs) {
    if (lhs[0] == rhs[0]) return lhs[1] < rhs[1];
    return lhs[0] < rhs[0];
  }

  static void print(const vector<vector<int>>& intervals) {
    for (const auto& it : intervals) debug("[{}, {}]\n", it[0], it[1]);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NON_OVERLAPPING_INTERVALS_H
