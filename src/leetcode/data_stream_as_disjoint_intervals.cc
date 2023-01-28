#ifndef LEETCODE_DATA_STREAM_AS_DISJOINT_INTERVALS_H
#define LEETCODE_DATA_STREAM_AS_DISJOINT_INTERVALS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <map>
#include <set>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

// class SummaryRanges {
//   std::set<int> set;
//
//  public:
//   SummaryRanges() : set(std::set<int>()) {}
//
//   void addNum(int value) { set.insert(value); }
//
//   vector<vector<int>> getIntervals() {
//     std::vector<vector<int>> res;
//     int prev = -2;
//     for (const auto num : set) {
//       if (num != prev + 1) {
//         res.push_back({num, num});
//         prev = num;
//       } else {
//         res[res.size() - 1][1] = num;
//         prev = num;
//       }
//     }
//     return res;
//   }
// };

class SummaryRanges {
  std::map<int, int> map;

 public:
  SummaryRanges() : map(std::map<int, int>()) {}

  void addNum(int value) {
    auto it = map.upper_bound(value);
    if (it != map.end()) {
      auto [start, end] = *it;
      // todo implement
    } else {
      map[value] = value;
    }
  }

  vector<vector<int>> getIntervals() {
    std::vector<vector<int>> res(map.size(), vector<int>(2));
    for (int i = 0; const auto [key, val] : map) {
      res[i][0] = key;
      res[i][1] = val;
      ++i;
    }
    return res;
  }
};
class Solution {
 public:
  int test() {
    SummaryRanges ranges;
    ranges.addNum(1);
    ranges.addNum(3);
    ranges.addNum(5);

    for (const auto& interval : ranges.getIntervals()) {
      debug("{} - {}\n", interval[0], interval[1]);
    }
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DATA_STREAM_AS_DISJOINT_INTERVALS_H
