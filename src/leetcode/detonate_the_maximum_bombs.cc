#ifndef LEETCODE_DETONATE_THE_MAXIMUM_BOMBS_H
#define LEETCODE_DETONATE_THE_MAXIMUM_BOMBS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
#include <unordered_set>
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
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    std::vector<std::vector<int>> adjacent(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j && inRange(bombs[i], bombs[j])) adjacent[i].push_back(j);
      }
    }

    std::queue<int> queue;
    std::unordered_set<int> all, unchecked, visited;
    for (int i = 0; i < n; ++i) all.insert(i);
    unchecked = all;

    int res = 0;
    while (!unchecked.empty()) {
      int check_index = *unchecked.begin();
      unchecked.erase(unchecked.begin());
      debug("check {}\n", check_index);

      queue.push(check_index);
      visited = all;
      visited.erase(check_index);

      int count = 0;
      while (!queue.empty()) {
        int visit_index = queue.front();
        queue.pop();
        ++count;
        
        unchecked.erase(visit_index);

        debug(" visit {}\n", visit_index);
        for (const auto adj : adjacent[visit_index])
          if (visited.find(adj) != visited.end()) {
            visited.erase(adj);
            queue.push(adj);
          }
      }
      res = std::max(res, count);
    }
    return res;
  }

  static inline bool inRange(const std::vector<int>& lhs,
                             const std::vector<int>& rhs) {
    return distance(lhs, rhs) <= lhs[2];
  }

  static inline float distance(const std::vector<int>& lhs,
                               const std::vector<int>& rhs) {
    return std::sqrt(std::pow(lhs[0] - rhs[0], 2) + std::pow(lhs[1] - rhs[1], 2));
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DETONATE_THE_MAXIMUM_BOMBS_H
