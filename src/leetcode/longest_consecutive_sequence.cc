#ifndef LEETCODE_LONGEST_CONSECUTIVE_SEQUENCE_H
#define LEETCODE_LONGEST_CONSECUTIVE_SEQUENCE_H

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

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
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() <= 1) {
      return nums.size();
    }
    std::sort(nums.begin(), nums.end());

    int sq = 1;
    int res = 0;
    int prev = nums[0];
    for (auto it = std::next(nums.begin()); it != nums.end(); ++it) {
      if (*it == prev) {
      } else if ((*it - prev) == 1) {
        ++sq;
      } else {
        res = std::max(res, sq);
        sq = 1;
      }
      prev = *it;
      // std::cout << *it << "\n";
    }
    return res = std::max(res, sq);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_CONSECUTIVE_SEQUENCE_H
