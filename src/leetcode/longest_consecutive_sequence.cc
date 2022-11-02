#ifndef LEETCODE_LONGEST_CONSECUTIVE_SEQUENCE_H
#define LEETCODE_LONGEST_CONSECUTIVE_SEQUENCE_H

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
  // int longestConsecutive(vector<int>& nums) {
  //   if (nums.size() <= 1) {
  //     return nums.size();
  //   }
  //   std::sort(nums.begin(), nums.end());

  //  int sq = 1;
  //  int res = 0;
  //  int prev = nums[0];
  //  for (auto it = std::next(nums.begin()); it != nums.end(); ++it) {
  //    if (*it == prev) {
  //    } else if ((*it - prev) == 1) {
  //      ++sq;
  //    } else {
  //      res = std::max(res, sq);
  //      sq = 1;
  //    }
  //    prev = *it;
  //    // std::cout << *it << "\n";
  //  }
  //  return res = std::max(res, sq);
  //}

  int longestConsecutive(vector<int>& nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());

    int res = 0;
    for (auto it : set) {
      if (set.find(it - 1) != set.end()) continue;
      int sq = 0;
      int curr = it;
      bool hasNext = true;
      while (hasNext) {
        auto next = set.find(curr + 1);
        hasNext = next != set.end();
        ++sq;
        if (hasNext) curr = *next;
      }
      res = std::max(res, sq);
      // std::cout << " -> " << it << "\n";
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_CONSECUTIVE_SEQUENCE_H
