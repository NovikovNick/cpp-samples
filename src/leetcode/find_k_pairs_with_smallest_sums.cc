#ifndef LEETCODE_FIND_K_PAIRS_WITH_SMALLEST_SUMS_H
#define LEETCODE_FIND_K_PAIRS_WITH_SMALLEST_SUMS_H
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
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = std::min<int>(k, nums1.size() * nums2.size());
    std::vector<std::vector<int>> res(n, std::vector<int>(2));

    return res;
  }

  /*vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
  { int n = std::min<int>(k, nums1.size() * nums2.size());
    std::vector<std::vector<int>> res(n, std::vector<int>(2));

    const auto comparator = [](const std::vector<int>& lhs,
                               const std::vector<int>& rhs) {
      return (lhs[0] + lhs[1]) < (rhs[0] + rhs[1]);
    };

    std::priority_queue<std::vector<int>,
                        std::vector<std::vector<int>>,
                        decltype(comparator)>
        max_heap(comparator);

    for (int i = 0; i < nums1.size(); ++i) {
      for (int j = 0; j < nums2.size(); ++j) {
        max_heap.push({nums1[i], nums2[j]});
        if (max_heap.size() > n) max_heap.pop();
      }
    }

    for (int i = n - 1; i >= 0; --i) {
      res[i][0] = max_heap.top()[0];
      res[i][1] = max_heap.top()[1];
      max_heap.pop();
    }
    return res;
  }*/
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_K_PAIRS_WITH_SMALLEST_SUMS_H
