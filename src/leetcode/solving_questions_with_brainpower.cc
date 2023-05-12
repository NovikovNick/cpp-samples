#ifndef LEETCODE_SOLVING_QUESTIONS_WITH_BRAINPOWER_H
#define LEETCODE_SOLVING_QUESTIONS_WITH_BRAINPOWER_H
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
  int n;

 public:
  long long mostPoints(vector<vector<int>>& questions) {
    n = questions.size();
    std::vector<long long> dp(n, 0);
    for (int i = 0; i < n; ++i) {
      long long sum = questions[i][0];
      for (int j = i + questions[i][1] + 1; j < n; ++j) {

        //if (dp[j] >= sum + questions[j][0]) break;
        //dp[j] = sum + questions[j][0];
        dp[j] = std::max(dp[j], sum + questions[j][0]);
      }
    }
    return *std::max_element(dp.begin(), dp.end());
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SOLVING_QUESTIONS_WITH_BRAINPOWER_H
