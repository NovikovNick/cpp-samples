#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_MINIMUM_ABSOLUTE_SUM_DIFFERENCE_H
#define LEETCODE_MINIMUM_ABSOLUTE_SUM_DIFFERENCE_H

namespace leetcode {

using namespace std;

using ConstIter = vector<int>::const_iterator;
using Iter = vector<int>::iterator;

int diff(ConstIter begin1, ConstIter end1, ConstIter begin2) {
  int res = 0;
  int diff = 0;
  std::cout << "Diff: ";
  while (begin1 != end1) {
    diff = std::abs(*begin1 - *begin2);
    res += diff;
    std::cout << std::format("|{:2d} - {:2d}| = ({:2d}) ", *begin1, *begin2, diff);
    ++begin1;
    ++begin2;
  }

  std::cout << std::format(" = {}\n", res);
  return res;
}

class Solution {
 public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ref(nums1.cbegin(), nums1.cend());

    int res = diff(ref.cbegin(), ref.cend(), nums2.cbegin());
    for (int i = 0; i < nums1.size(); ++i) {
      for (int j = 0; j < nums1.size(); ++j) {
        if (i == j) {
          continue;
        }
        ref[i] = ref[j];
        res = std::min(res, diff(ref.cbegin(), ref.cend(), nums2.cbegin()));
        std::copy(nums1.cbegin(), nums1.cend(), ref.begin());
      }
    }

    std::cout << std::format("--------\n");
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_ABSOLUTE_SUM_DIFFERENCE_H
