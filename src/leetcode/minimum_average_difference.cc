#ifndef LEETCODE_MINIMUM_AVERAGE_DIFFERENCE_H
#define LEETCODE_MINIMUM_AVERAGE_DIFFERENCE_H
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
  using NUM = uint64_t;

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
  NUM absDiff(const NUM& a, const NUM& b) { return a > b ? a - b : b - a; }

  int minimumAverageDifference(vector<int>& nums) {
    int n = nums.size(), res = 0, min = 100001;
    NUM front = std::accumulate(nums.begin(), nums.end(), 0l), back = 0, diff;
    for (int i = 1, j = n - 1; const auto& num : nums) {
      back += num;
      front -= num;
      diff = absDiff(back / i, j == 0 ? 0 : front / j);

      debug("{:2d}. |{:2d}/{:2d} - {:2d}/{:2d}| = |{:2d} - {:2d}| = {:2d} \n",
            i - 1, back, i, front, j, back / i, j == 0 ? 0 : front / j, diff);

      if (diff < min) {
        res = i - 1;
        min = diff;
      }
      ++i;
      --j;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_AVERAGE_DIFFERENCE_H
