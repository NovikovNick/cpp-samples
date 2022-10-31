#ifndef LEETCODE_DAILY_TEMPERATURES_H
#define LEETCODE_DAILY_TEMPERATURES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace leetcode {

using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int size = temperatures.size();
    std::vector<int> res(size, 0);
    for (int i = 0; i < size; ++i) {
      int j = i;
      bool greater = temperatures[i] >= temperatures[j];
      for (; j < size && greater; ++j)
        greater = temperatures[i] >= temperatures[j];
      res[i] = greater ? 0 : j - i - 1;
    }
    // for (auto it : res) std::cout << std::format(" - {}\n", it);
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DAILY_TEMPERATURES_H
