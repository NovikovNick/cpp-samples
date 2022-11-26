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

struct Job {
  int start, end, profit;
  Job(const int start, const int end, const int profit)
      : start(start), end(end), profit(profit) {}

  static bool compareByEndAsc(const Job& a, const Job& b) {
    return a.end < b.end;
  }
};

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
  int lowerBoundBinarySearch(const std::vector<Job>& jobs, const int val,
                             int low, int high) {
    int res = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (jobs[mid].end <= val) {
        res = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return res;
  }

  int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                    vector<int>& profit) {
    int n = profit.size();

    std::vector<Job> jobs;
    for (int i = 0; i < n; ++i)
      jobs.emplace_back(startTime[i], endTime[i], profit[i]);

    std::sort(jobs.begin(), jobs.end(), Job::compareByEndAsc);

    std::vector<int> dp(n, 0);
    dp[0] = jobs[0].profit;
    for (int i = 1; i < n; ++i) {
      int start = jobs[i].start;
      // find end time less or equal then start time;
      int prev = lowerBoundBinarySearch(jobs, start, 0, i - 1);
      int profit = prev == -1 ? jobs[i].profit : jobs[i].profit + dp[prev];
      dp[i] = std::max(dp[i - 1], profit);
    }

    return dp[n - 1];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_PROFIT_IN_JOB_SCHEDULING_H
