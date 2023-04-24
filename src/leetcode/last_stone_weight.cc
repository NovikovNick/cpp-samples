#ifndef LEETCODE_LAST_STONE_WEIGHT_H
#define LEETCODE_LAST_STONE_WEIGHT_H
#include <algorithm>
#include <format>
#include <iostream>
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

class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    std::priority_queue<int> max_heap(stones.begin(), stones.end());

    int y, x;
    while (max_heap.size() > 1) {
      y = max_heap.top();    
      max_heap.pop();
      x = max_heap.top();
      max_heap.pop();
      if (y != x) max_heap.push(y - x);
    }
    return max_heap.empty() ? 0 : max_heap.top();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LAST_STONE_WEIGHT_H
