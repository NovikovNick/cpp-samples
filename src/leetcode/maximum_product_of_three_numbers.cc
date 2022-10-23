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
    std::sort(nums.begin(), nums.end());

    int start = nums[0] * nums[1];
    int end = nums[nums.size() - 1] * nums[nums.size() - 2];
    
    return std::max(start * nums[nums.size() - 1], end * nums[nums.size() - 3]);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_H
