#ifndef LEETCODE_CONTAINS_DUPLICATE_III_H
#define LEETCODE_CONTAINS_DUPLICATE_III_H
#include <algorithm>
#include <format>
#include <iostream>
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

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                     int valueDiff) {
    int n = nums.size();

    if (indexDiff <= valueDiff) {
      for (int i = 0; i < n; ++i)
        for (int j = i + 1, sz = std::min((i + indexDiff), n - 1); j <= sz; ++j)
          if (std::abs(nums[i] - nums[j]) <= valueDiff) return true;

    } else {
      std::vector<pair<int, int>> sorted(n);
      for (int i = 0; i < n; ++i) sorted[i] = std::make_pair(nums[i], i);
      std::sort(sorted.begin(), sorted.end());

      for (int i = 0; i < n; ++i) {
        int j = i + 1;
        while (j < n && (sorted[j].first - sorted[i].first) <= valueDiff) {
          if (std::abs(sorted[j].second - sorted[i].second) <= indexDiff)
            return true;
          ++j;
        }
      }
    }
    return false;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_CONTAINS_DUPLICATE_III_H
