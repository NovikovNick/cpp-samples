#ifndef LEETCODE_DELETE_AND_EARN_H
#define LEETCODE_DELETE_AND_EARN_H
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
  int deleteAndEarn(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> dp(4);
    int prev = nums[0];
    for (const auto& c : nums) {
      if (prev == c) {
        dp[0] += c;
      } else if ((prev + 1) == c) {
        shift_right(dp);
        dp[0] = std::max(dp[2], dp[3]) + c;
      } else {
        shift_right(dp);
        dp[0] = std::max(dp[1], std::max(dp[2], dp[3])) + c;
      }
      prev = c;
    }
    return std::max(dp[1], dp[0]);
  }

  void shift_right(std::vector<int>& dp) {
    // std::shift_right(dp.begin(), dp.end(), 1); only cpp20
    dp[3] = dp[2];
    dp[2] = dp[1];
    dp[1] = dp[0];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DELETE_AND_EARN_H
