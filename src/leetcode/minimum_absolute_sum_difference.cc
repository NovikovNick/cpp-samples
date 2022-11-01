#include <algorithm>
#include <format>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_MINIMUM_ABSOLUTE_SUM_DIFFERENCE_H
#define LEETCODE_MINIMUM_ABSOLUTE_SUM_DIFFERENCE_H

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
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    std::set<int> set(nums1.begin(), nums1.end());

    unsigned long long sum = 0;
    int dist = 0;
    for (int i = 0, sz = nums1.size(); i < sz; ++i) {
      int diff = std::abs(nums1[i] - nums2[i]);
      sum += diff;
      if (diff <= dist) {
        continue;
      }
      auto it = set.lower_bound(nums2[i]);
      dist = std::max(dist, diff - std::abs(*it - nums2[i]));

      if (it != set.begin()) {
        dist = std::max(dist, diff - std::abs(*(std::prev(it)) - nums2[i]));
      }

      /*std::cout << std::format(
          "sum[{}] = {}. diff is |{} - {}| = {}. Lower = {}, upper = {}\n", i,
          sum, nums1[i], nums2[i], diff, *less, *great);*/

    }
    return (sum - dist) % 1000000007;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_ABSOLUTE_SUM_DIFFERENCE_H
