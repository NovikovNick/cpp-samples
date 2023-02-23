#ifndef LEETCODE_IPO_H
#define LEETCODE_IPO_H
#include <algorithm>
#include <format>
#include <iostream>
#include <list>
#include <map>
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
using PAIR = std::pair<int, int>;
class Solution {
 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
                           vector<int>& capitals) {
    int n = profits.size();
    std::vector<PAIR> pairs;
    for (int i = 0; i < n; ++i) pairs.push_back({capitals[i], profits[i]});

    std::sort(pairs.begin(), pairs.end());

    std::priority_queue<int> max_heap;
    int i = 0;
    for (; i < n && pairs[i].first <= w; ++i) max_heap.push(pairs[i].second);

    while (!max_heap.empty() && k != 0) {
      w += max_heap.top();
      max_heap.pop();
      --k;
      for (; i < n && pairs[i].first <= w; ++i) max_heap.push(pairs[i].second);
    }
    return w;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_IPO_H
