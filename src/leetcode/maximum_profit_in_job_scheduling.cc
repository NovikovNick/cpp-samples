#ifndef LEETCODE_MAXIMUM_PROFIT_IN_JOB_SCHEDULING_H
#define LEETCODE_MAXIMUM_PROFIT_IN_JOB_SCHEDULING_H
#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
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
  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    int n = profit.size();

    std::vector<int> ordered_indexes(n);
    std::iota(ordered_indexes.begin(), ordered_indexes.end(), 0);
    std::sort(ordered_indexes.begin(), ordered_indexes.end(),
              [startTime](const int& a, const int& b) {
                return startTime[a] < startTime[b];
              });
    std::vector<int> dp(n);
    dp[0] = profit[ordered_indexes[0]];
    int res = dp[0];
    for (int i = 1; i < n; ++i) {
      int curr = ordered_indexes[i];
      int curr_start_time = startTime[curr];
      dp[i] = profit[curr];
      for (int j = i - 1; j >= 0; --j) {
        int prev = ordered_indexes[j];
        int prev_end_time = endTime[prev];
        if (prev_end_time <= curr_start_time) {
          dp[i] = std::max(dp[i], profit[curr] + dp[j]);
        }
      }
      res = std::max(dp[i], res);
    }

    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_PROFIT_IN_JOB_SCHEDULING_H
