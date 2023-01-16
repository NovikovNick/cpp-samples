#ifndef LEETCODE_INSERT_INTERVAL_H
#define LEETCODE_INSERT_INTERVAL_H
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
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    int merge_begin = 0;
    int merge_end = 0;
    bool overlap = false, inserted = false;
    for (auto it = intervals.begin(); it != intervals.end(); ++it) {
      int& xn = newInterval[0];
      int& yn = newInterval[1];
      int& xi = (*it)[0];
      int& yi = (*it)[1];

      if (xn > yi) continue;
      if (yn < xi) {
        intervals.insert(it, newInterval);
        inserted = true;
        break;
      }
      if (yn <= yi) {
        xi = std::min(xn, xi);
        inserted = true;
        break;
      }
      if (!overlap) {
        xn = std::min(xn, xi);
        overlap = true;
        merge_begin = std::distance(intervals.begin(), it);
        merge_end = merge_begin + 1;
      } else {
        merge_end = std::distance(intervals.begin(), it) + 1;
      }
    }
    if (overlap)
      intervals.erase(intervals.begin() + merge_begin,
                      intervals.begin() + merge_end);
    if (!inserted) intervals.push_back(newInterval);
    return intervals;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_INSERT_INTERVAL_H
