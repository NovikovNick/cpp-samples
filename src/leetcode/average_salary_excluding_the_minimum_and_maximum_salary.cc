#ifndef LEETCODE_AVERAGE_SALARY_EXCLUDING_THE_MINIMUM_AND_MAXIMUM_SALARY_H
#define LEETCODE_AVERAGE_SALARY_EXCLUDING_THE_MINIMUM_AND_MAXIMUM_SALARY_H
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
  double average(vector<int>& salary) {
    int min = 1e6 + 1;
    int max = 0;
    uint64_t sum = 0;
    for (const auto it : salary) {
      sum += it;
      min = std::min(min, it);
      max = std::max(max, it);
    }
    double denominator = (salary.size() - 2);
    return (sum - min - max) / denominator;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_AVERAGE_SALARY_EXCLUDING_THE_MINIMUM_AND_MAXIMUM_SALARY_H
