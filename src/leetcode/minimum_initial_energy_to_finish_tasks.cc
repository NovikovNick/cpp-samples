#include <algorithm>
#include <format>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_MINIMUM_INITIAL_ENERGY_TO_FINISH_TASKS_H
#define LEETCODE_MINIMUM_INITIAL_ENERGY_TO_FINISH_TASKS_H

namespace leetcode {

using namespace std;

class Solution {
 public:
  /*int minimumEffort(vector<vector<int>>& tasks) {
    std::sort(tasks.begin(), tasks.end(),
              [](const std::vector<int>& a1, const std::vector<int>& a2) {
                auto d1 = a1[1] - a1[0];
                auto d2 = a2[1] - a2[0];
                if (d1 < d2) return true;
                if (d1 == d2) return a1[0] > a2[0];
                return false;
              });
    int res = 0;
    for (auto task : tasks) {
      res = std::max(res + task[0], task[1]);
      std::cout << std::format(
          "delay {:2d}, actual {:2d}, minimum {:2d}. res = {:2d}\n",
          task[1] - task[0], task[0], task[1], res);
    }
    return res;
  }*/

  int minimumEffort(vector<vector<int>>& tasks) {
    auto diffComparator = [](const std::vector<int>& a1,
                             const std::vector<int>& a2) {
      return (a1[1] - a1[0]) < (a2[1] - a2[0]);
    };
    auto reducer = [](int res, const std::vector<int>& task) {
      return std::move(std::max(res + task[0], task[1]));
    };
    std::sort(tasks.begin(), tasks.end(), diffComparator);
    return std::accumulate(tasks.begin(), tasks.end(), 0, reducer);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_INITIAL_ENERGY_TO_FINISH_TASKS_H
