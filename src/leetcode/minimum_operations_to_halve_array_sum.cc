#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_MINIMUM_OPERATIONS_TO_HALVE_ARRAY_SUM_H
#define LEETCODE_MINIMUM_OPERATIONS_TO_HALVE_ARRAY_SUM_H

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
  int halveArray(vector<int>& nums) {
    double sum = std::accumulate(nums.begin(), nums.end(), 0.0);
    std::priority_queue<double> queue(nums.begin(), nums.end());

    double sentinel = sum / 2.0;
    double half = 0;
    int res = 0;

    while (sentinel > 0) {
      auto it = queue.top();
      queue.pop();
      half = it / 2.0;
      // std::cout << std::format("{:8.2f} - ({:2.2f} / 2 = {:2.2f}) = {:8.2f}\n", sentinel, it, half, sentinel - half);
      sentinel -= half;
      ++res;
      queue.push(half);
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_OPERATIONS_TO_HALVE_ARRAY_SUM_H
