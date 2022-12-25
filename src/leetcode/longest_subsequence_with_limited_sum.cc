#ifndef LEETCODE_LONGEST_SUBSEQUENCE_WITH_LIMITED_SUM_H
#define LEETCODE_LONGEST_SUBSEQUENCE_WITH_LIMITED_SUM_H
#include <algorithm>
#include <format>
#include <iostream>
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }  
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size(), m = queries.size();
    std::vector<int> res(m);
    std::sort(nums.begin(), nums.end());
    for (int q = 0, query = 0; q < m; ++q) {
      query = queries[q];
      queries[q] = 0;
      for (int sum = 0, j = 0; j < n; ++j)
        if ((sum += nums[j]) <= query) ++queries[q];
    }
    return queries;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_SUBSEQUENCE_WITH_LIMITED_SUM_H
