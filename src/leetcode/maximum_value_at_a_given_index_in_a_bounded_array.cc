#ifndef LEETCODE_MAXIMUM_VALUE_AT_A_GIVEN_INDEX_IN_A_BOUNDED_ARRAY_H
#define LEETCODE_MAXIMUM_VALUE_AT_A_GIVEN_INDEX_IN_A_BOUNDED_ARRAY_H
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
  int maxValue(const int n, const int index, const int maxSum) {
    
    if (n == 1) return maxSum;  
      
    const int lhsBound = index;
    const int rhsBound = n - 1 - index;

    int lhs = 0;
    int mid = 1;
    int rhs = 0;

    int res = 1;
    int sum = n;
    while (sum <= maxSum) {
      res = mid;
      debug("lhs:{:3d}, mid:{:3d}, rhs:{:3d} => sum {}\n", lhs, mid, rhs, sum);

      sum += lhs + 1 + rhs;
      if (lhs < lhsBound) ++lhs;
      if (rhs < rhsBound) ++rhs;
      ++mid;
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMUM_VALUE_AT_A_GIVEN_INDEX_IN_A_BOUNDED_ARRAY_H
