#ifndef LEETCODE_MAXIMUM_LENGTH_OF_PAIR_CHAIN_H
#define LEETCODE_MAXIMUM_LENGTH_OF_PAIR_CHAIN_H
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
  int findLongestChain(vector<vector<int>>& pairs) {
    int n = pairs.size();
    std::sort(pairs.begin(), pairs.end(), compare);

    std::vector<int> dp(n, 1);

    int res = 1;
    for (int forward = 1; forward < n; ++forward) {
      for (int backward = forward - 1; backward >= 0; --backward) {
        if (strictGreater(pairs[backward], pairs[forward])) {
          dp[forward] = std::max(dp[forward], dp[backward] + 1);
          res = std::max(res, dp[forward]);
        }
      }
    }
    return res;
  }

  inline bool strictGreater(const std::vector<int>& lhs,
                            const std::vector<int>& rhs) const noexcept {
    return lhs[1] < rhs[0];
  }

  static bool compare(const std::vector<int>& lhs,
                      const std::vector<int>& rhs) noexcept {
    if (lhs[0] == rhs[0]) return lhs[1] < rhs[1];
    return lhs[1] < rhs[1];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_LENGTH_OF_PAIR_CHAIN_H
