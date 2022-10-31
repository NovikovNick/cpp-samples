#ifndef LEETCODE_DAILY_TEMPERATURES_H
#define LEETCODE_DAILY_TEMPERATURES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

namespace leetcode {

using namespace std;

class Solution {
 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int size = temperatures.size();
    std::vector<int> res(size, 0);
    std::stack<int> stack;
    for (int i = 0; i < size; ++i) {
      // std::cout << std::format("Checking {:2d}:", temperatures[i]);
      while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
        // std::cout << std::format("-{}({})", temperatures[stack.top()], i - stack.top());
        res[stack.top()] = i - stack.top();
        stack.pop();
      }
      stack.push(i);
      // std::cout << std::format("\n");
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DAILY_TEMPERATURES_H
