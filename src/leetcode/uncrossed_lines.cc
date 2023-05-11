#ifndef LEETCODE_UNCROSSED_LINES_H
#define LEETCODE_UNCROSSED_LINES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
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
 public:
  int maxUncrossedLines(vector<int>& n1, vector<int>& n2) {
    std::vector<std::queue<int>> hash1(2001), hash2(2001);

    int count = 0;
    int prev1 = -1, prev2 = -1;

    int n = std::max(n1.size(), n2.size());
    for (int i = 0; i < n; ++i) {
      if (i < n1.size()) hash1[n1[i]].push(i);
      if (i < n2.size()) hash2[n2[i]].push(i);

      if (i < n2.size() && !hash1[n2[i]].empty() && !hash2[n2[i]].empty()) {
        auto val = n2[i];
        auto prev_min = std::min(prev1, prev2);
        auto prev_max = std::max(prev1, prev2);

        auto curr_min = std::min(hash1[val].front(), hash2[val].front());
        auto curr_max = std::max(hash1[val].front(), hash2[val].front());

        if (curr_min > prev_min && curr_max > prev_max) {
          prev1 = hash1[val].front();
          hash1[val].pop();
          prev2 = hash2[val].front();
          hash2[val].pop();
          ++count;
        } else if (curr_max < prev_max) {
          prev1 = curr_min;
          prev2 = curr_max;
        }
      }

      if (i < n1.size() && !hash1[n1[i]].empty() && !hash2[n1[i]].empty()) {
        auto val = n1[i];
        auto prev_min = std::min(prev1, prev2);
        auto prev_max = std::max(prev1, prev2);

        auto curr_min = std::min(hash1[val].front(), hash2[val].front());
        auto curr_max = std::max(hash1[val].front(), hash2[val].front());

        if (curr_min > prev_min && curr_max > prev_max) {
          prev1 = hash1[val].front();
          hash1[val].pop();
          prev2 = hash2[val].front();
          hash2[val].pop();
          ++count;
        } else if (curr_max < prev_max) {
          prev1 = curr_min;
          prev2 = curr_max;
        }
      }
    }

    /*for (int i = 0; i < n1.size(); ++i) debug("{:3d} ", n1[i]);
    debug("\n");
    for (int i = 0; i < n2.size(); ++i) debug("{:3d} ", n2[i]);
    debug("\n");*/
    return count;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_UNCROSSED_LINES_H
