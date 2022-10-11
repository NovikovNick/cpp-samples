#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_TWO_SUM_H
#define LEETCODE_TWO_SUM_H

namespace leetcode {

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::vector<int> ordered(nums.size());

    std::partial_sort_copy(nums.begin(), nums.end(), ordered.begin(),
                           ordered.end());

    int sum;
    auto left = ordered.begin();
    auto right = std::prev(ordered.end());
    while (left != right) {
      sum = *left + *right;
      if (sum > target) {
        right = std::prev(right);
      } else if (sum < target) {
        left = std::next(left);
      } else {
        int fstIndex = std::distance(
            nums.begin(), std::find(nums.begin(), nums.end(), *left));
        int sndIndex = std::distance(
            nums.begin(),
            std::next(std::find(nums.rbegin(), nums.rend(), *right)).base());

        return {fstIndex, sndIndex};
      }
    }

    throw "invalid range";
  }
};
}  // namespace leetcode
#endif  // LEETCODE_TWO_SUM_H
