#ifndef LEETCODE_COURSE_SCHEDULE_H
#define LEETCODE_COURSE_SCHEDULE_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
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
  std::unordered_set<int> visited;

 public:
  bool canFinish(int n, vector<vector<int>>& prerequisites) {
    std::vector<std::vector<int>> dependencies(n);
    for (const auto& prerequisite : prerequisites) {
      dependencies[prerequisite[0]].push_back(prerequisite[1]);
    }

    for (int i = 0; i < n; ++i) {
      if (dependencies[i].empty()) continue;
      if (hasCircle(i, dependencies)) return false;
    }
    return true;
  }

  bool hasCircle(const int cur, const std::vector<std::vector<int>>& dependencies) {
    if (!visited.insert(cur).second) return true;  // (!)
    //debug("{}\n", cur);
    for (const auto dependency : dependencies[cur]) {
      if (hasCircle(dependency, dependencies)) return true;
    }
    visited.erase(cur);
    return false;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_COURSE_SCHEDULE_H
