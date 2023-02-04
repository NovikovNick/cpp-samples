#ifndef LEETCODE_MINIMUM_ABSOLUTE_DIFFERENCE_H
#define LEETCODE_MINIMUM_ABSOLUTE_DIFFERENCE_H
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
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    int n = arr.size();
    std::sort(arr.begin(), arr.end());

    int min_diff = INT_MAX;
    for (int i = 1; i < n; ++i)
      min_diff = std::min(min_diff, arr[i] - arr[i - 1]);

    std::vector<std::vector<int>> res;
    for (int i = 1; i < n; ++i)
      if (arr[i] - arr[i - 1] == min_diff) res.push_back({arr[i - 1], arr[i]});
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_ABSOLUTE_DIFFERENCE_H
