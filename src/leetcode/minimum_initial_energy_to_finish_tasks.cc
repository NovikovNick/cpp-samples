#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
#include <vector>

#ifndef LEETCODE_MINIMUM_INITIAL_ENERGY_TO_FINISH_TASKS_H
#define LEETCODE_MINIMUM_INITIAL_ENERGY_TO_FINISH_TASKS_H

namespace leetcode {

using namespace std;

class Solution {
 public:
  int minimumEffort(vector<vector<int>>& tasks) {
    std::sort(tasks.begin(), tasks.end(),
              [](const std::vector<int>& a1, const std::vector<int>& a2) {
                auto d1 = a1[1] - a1[0];
                auto d2 = a2[1] - a2[0];
                // return d1 == d2 ? d1 > d2 : a1[0] < a2[0];
                return d1 < d2;
              });
    int res = 0;
    for (auto task : tasks) {
      res = std::max(res + task[0], task[1]);
      /*std::cout << std::format(
                       "delay {:2d}, actual {:2d}, minimum {:2d}. res = {:2d}",
                       task[1] - task[0], task[0], task[1], res)
                << std::endl;*/
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMUM_INITIAL_ENERGY_TO_FINISH_TASKS_H
