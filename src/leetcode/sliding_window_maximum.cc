#ifndef LEETCODE_SLIDING_WINDOW_MAXIMUM_H
#define LEETCODE_SLIDING_WINDOW_MAXIMUM_H
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
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    int res_size = n - k + 1;

    std::set<std::pair<int, int>> window;
    for (int i = 0; i < k; ++i) {
      window.emplace(nums[i], i);
    }

    std::vector<int> res(res_size);
    for (int i = 0; i < res_size - 1; ++i) {
      res[i] = window.rbegin()->first;
      window.erase({nums[i], i});
      window.insert({nums[i + k], i + k});
    }
    res[res_size - 1] = window.rbegin()->first;
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SLIDING_WINDOW_MAXIMUM_H
