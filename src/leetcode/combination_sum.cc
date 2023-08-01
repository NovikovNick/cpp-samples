#ifndef LEETCODE_COMBINATION_SUM_H
#define LEETCODE_COMBINATION_SUM_H
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
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> curr;
    backtracking(0, target, 0, curr, candidates, res);
    return res;
  }

  void backtracking(int i,
                    const int target,
                    int sum,
                    std::vector<int>& curr,
                    std::vector<int>& candidates,
                    std::vector<std::vector<int>>& res) {
    for (const auto num : curr) debug("{} ", num);
    debug(" = {}\n", sum);

    if (sum == target) {
      res.push_back(curr);
      return;
    }

    for (; i < candidates.size(); ++i) {
      sum += candidates[i];
      if (sum <= target) {
        curr.push_back(candidates[i]);
        backtracking(i, target, sum, curr, candidates, res);
        curr.pop_back();
      }
      sum -= candidates[i];
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COMBINATION_SUM_H
