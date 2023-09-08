#ifndef LEETCODE_MAX_CONSECUTIVE_ONES_III_H
#define LEETCODE_MAX_CONSECUTIVE_ONES_III_H
#include <algorithm>
#include <format>
#include <iostream>
#include <optional>
#include <queue>
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
  int longestOnes(vector<int>& nums, int k) {
    int res = 0;
    int sum = 0;
    int count_one = 0;
    std::queue<int> q;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        ++sum;
        q.push(count_one + 1);
        count_one = 0;

        if (q.size() > k) {
          sum -= q.front();
          q.pop();
        }
      } else {
        ++count_one;
        ++sum;
      }
      res = std::max(res, sum);
    }

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAX_CONSECUTIVE_ONES_III_H
