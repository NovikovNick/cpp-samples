#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_H
#define LEETCODE_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_H

namespace leetcode {

using namespace std;

class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    std::partial_sort(nums.rbegin(), nums.rbegin() + 2, nums.rend(),
                      std::greater<int>());
    std::partial_sort(nums.begin(), nums.end() - 2, nums.end());

    int size = nums.size();
    return std::max(nums[0] * nums[1] * nums[size - 1],
                    nums[size - 3] * nums[size - 2] * nums[size - 1]);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_H
