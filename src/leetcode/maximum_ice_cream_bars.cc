#ifndef LEETCODE_MAXIMUM_ICE_CREAM_BARS_H
#define LEETCODE_MAXIMUM_ICE_CREAM_BARS_H
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
  int maxIceCream(vector<int>& costs, int coins) {
    int n = costs.size();
    std::sort(costs.begin(), costs.end());

    int res = 0;
    for (int i = 0; i < n; ++i) {
      coins -= costs[i];
      if (coins >= 0) {
        ++res;
      } else {
        return res;
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_ICE_CREAM_BARS_H
