#ifndef LEETCODE_DOMINO_AND_TROMINO_TILING_H
#define LEETCODE_DOMINO_AND_TROMINO_TILING_H
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
  int MOD = 1000000007;
 public:
  int numTilings(int n) {
    if (n < 3) return n;
    std::vector<uint64_t> dp{0, 1, 1, 2};
    for (int i = 3; i <= n; ++i) {
      std::swap(dp[0], dp[1]);
      std::swap(dp[1], dp[2]);
      std::swap(dp[2], dp[3]);
      dp[3] = (dp[2] * 2 + dp[0]) % MOD;
    }
    return dp[3];
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DOMINO_AND_TROMINO_TILING_H
