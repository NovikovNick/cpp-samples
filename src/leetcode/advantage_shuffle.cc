#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_TWO_SUM_H
#define LEETCODE_TWO_SUM_H

namespace leetcode {

using namespace std;

class Solution {
 public:
  // vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
  //   std::vector<int> res(nums1.size());
  //   std::vector<int> orderedNums1(nums1.size());
  //   std::partial_sort_copy(nums1.begin(), nums1.end(), orderedNums1.begin(),
  //                          orderedNums1.end());

  //  for (int i = 0; auto it : nums2) {
  //    auto pos = std::upper_bound(orderedNums1.begin(), orderedNums1.end() -
  //    i, it); if (pos == orderedNums1.end()) {
  //      pos = orderedNums1.begin();
  //    }
  //    res[i++] = *pos;

  //    std::rotate(pos, pos + 1, orderedNums1.end());
  //    // orderedNums1.erase(orderedNums1.end() - 1, orderedNums1.end());
  //  }
  //  return res;
  //}

  vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    std::vector<int> orderedNums1(nums1.size());
    std::partial_sort_copy(nums1.begin(), nums1.end(), orderedNums1.begin(),
                           orderedNums1.end());
    std::vector<int> orderedNums2(nums1.size());
    std::partial_sort_copy(nums2.begin(), nums2.end(), orderedNums2.begin(),
                           orderedNums2.end());

    std::unordered_map<int, std::deque<int>> assigned(nums1.size());
    std::deque<int> remaining;

    auto it1 = orderedNums1.begin(), it2 = orderedNums2.begin();
    while (it1 != orderedNums1.end() && it2 != orderedNums2.end()) {
      if (*it1 > *it2) {
        assigned[*it2].push_back(*it1);
        ++it1;
        ++it2;
      } else {
        remaining.push_back(*it1);
        ++it1;
      }
    }

    std::vector<int> res(nums2.size());
    for (int i = 0; auto num2 : nums2) {
      auto r = assigned.find(num2);
      if (r != assigned.end()) {
        res[i] = r->second.back();
        r->second.pop_back();
        if (r->second.empty()) {
          assigned.erase(r);
        }
      } else {
        res[i] = remaining.back();
        remaining.pop_back();
      }
      ++i;
    }

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_TWO_SUM_H
