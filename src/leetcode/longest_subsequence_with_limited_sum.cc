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
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size(), m = queries.size();
    std::vector<int> res(m);

    for (int q = 0; q < m; ++q) {
      std::priority_queue<int> queue;
      for (int sum = 0, j = 0; j < n; ++j) {
        if (nums[j] > queries[q]) continue;
        queue.push(nums[j]);
        sum += nums[j];
        if (sum > queries[q]) {
          sum -= queue.top();
          queue.pop();
        }
        res[q] = std::max<int>(queue.size(), res[q]);
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_SUBSEQUENCE_WITH_LIMITED_SUM_H
