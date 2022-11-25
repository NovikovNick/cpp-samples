#ifndef LEETCODE_SUM_OF_SUBARRAY_MINIMUMS_H
#define LEETCODE_SUM_OF_SUBARRAY_MINIMUMS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
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
  int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    std::stack<int> stack;  // monotonic asc stack
    uint64_t sum = 0;
    for (int i = 0; i <= n; ++i) {
      while (!stack.empty() && (i == n || arr[i] <= arr[stack.top()])) {
        int mid = stack.top();
        stack.pop();
        int nxt = i;
        int prv = stack.empty() ? -1 : stack.top();

        debug("{:3d}({}) - {:3d}|{:3d}|{:3d}\n", arr[mid], mid, prv, mid, nxt);

        uint64_t count = (mid - prv) * (nxt - mid);
        sum = (sum + count * arr[mid]) % MOD;
      }
      stack.push(i);
    }
    return sum;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SUM_OF_SUBARRAY_MINIMUMS_H
