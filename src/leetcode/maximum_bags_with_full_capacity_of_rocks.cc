#ifndef LEETCODE_MAXIMUM_BAGS_WITH_FULL_CAPACITY_OF_ROCKS_H
#define LEETCODE_MAXIMUM_BAGS_WITH_FULL_CAPACITY_OF_ROCKS_H
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
  int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int n = capacity.size();
    for (int i = 0; i < n; ++i) capacity[i] -= rocks[i];
    std::sort(capacity.begin(), capacity.end());

    for (int i = 0; i < n; ++i) {
      additionalRocks -= capacity[i];
      if (additionalRocks < 0) return i;
    };
    return n;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_BAGS_WITH_FULL_CAPACITY_OF_ROCKS_H
