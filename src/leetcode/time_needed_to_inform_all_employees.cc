#ifndef LEETCODE_TIME_NEEDED_TO_INFORM_ALL_EMPLOYEES_H
#define LEETCODE_TIME_NEEDED_TO_INFORM_ALL_EMPLOYEES_H
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
  std::vector<std::vector<int>> employees;
  int max_inform_time = 0;

 public:
  int numOfMinutes(int n,
                   int headId,
                   vector<int>& manager,
                   vector<int>& informTime) {
    employees.resize(n);
    for (int i = 0; i < n; ++i)
      if (manager[i] >= 0) employees[manager[i]].push_back(i);

    dfs(headId, 0, informTime);

    return max_inform_time;
  }

  void dfs(const int employee,
           int currentInformTime,
           const std::vector<int>& informTime) {
    currentInformTime += informTime[employee];
    max_inform_time = std::max(max_inform_time, currentInformTime);
    for (const auto it : employees[employee]) dfs(it, currentInformTime, informTime);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_TIME_NEEDED_TO_INFORM_ALL_EMPLOYEES_H
