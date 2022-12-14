#ifndef LEETCODE_HOUSE_ROBBER_H
#define LEETCODE_HOUSE_ROBBER_H
#include <algorithm>
#include <format>
#include <iostream>
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  } 
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    if (n == 2) return std::max(nums[0], nums[1]);
    nums[2] += nums[0];

    for (int i = 3; i < n; ++i) nums[i] += std::max(nums[i - 2], nums[i - 3]);

    return std::max(nums[n - 1], nums[n - 2]);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_HOUSE_ROBBER_H
