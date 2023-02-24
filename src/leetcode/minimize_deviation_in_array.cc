#ifndef LEETCODE_MINIMIZE_DEVIATION_IN_ARRAY_H
#define LEETCODE_MINIMIZE_DEVIATION_IN_ARRAY_H
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
  int minimumDeviation(vector<int>& nums) {
    std::priority_queue<int> even_max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> odd_min_heap;
    int even_min = INT_MAX;
    int odd_max = INT_MIN;

    for (const auto num : nums) {
      if (isOdd(num)) {
        odd_max = std::max(odd_max, num);
        odd_min_heap.push(num);
      } else {
        even_min = std::min(even_min, num);
        even_max_heap.push(num);
      }
    }

    if (odd_min_heap.empty()) {
      while (!isOdd(even_max_heap.top())) {
        int num = even_max_heap.top() >> 1;
        even_max_heap.pop();
        even_max_heap.push(num);

        even_min = std::min(num, even_min);
      }
      return even_max_heap.top() - even_min;
    }

    if (even_max_heap.empty()) {
      int res = odd_max - odd_min_heap.top();
      while (isOdd(odd_min_heap.top())) {
        int num = odd_min_heap.top() << 1;
        odd_min_heap.pop();
        odd_min_heap.push(num);

        odd_max = std::max(num, odd_max);

        if (res <= odd_max - odd_min_heap.top()) return res;
        res = odd_max - odd_min_heap.top();
      }
      return res;
    }

    int res = std::max(even_max_heap.top(), odd_max) -
              std::min(odd_min_heap.top(), even_min);
    int next_res = res;
    while ((!isOdd(even_max_heap.top()) && even_max_heap.top() > odd_max) ||
           (isOdd(odd_min_heap.top()) && odd_min_heap.top() < even_min)) {

      while (!isOdd(even_max_heap.top()) && even_max_heap.top() > odd_max) {
        int num = even_max_heap.top() >> 1;
        even_max_heap.pop();
        even_max_heap.push(num);

        even_min = std::min(num, even_min);

        next_res = std::max(even_max_heap.top(), odd_max) -
                   std::min(odd_min_heap.top(), even_min);

        if (res < next_res) return res;
        res = next_res;
      }

      while (isOdd(odd_min_heap.top()) && odd_min_heap.top() < even_min) {
        int num = odd_min_heap.top() << 1;
        odd_min_heap.pop();
        odd_min_heap.push(num);
        odd_max = std::max(num, odd_max);

        next_res = std::max(even_max_heap.top(), odd_max) -
                   std::min(odd_min_heap.top(), even_min);

        if (res < next_res) return res;
        res = next_res;
      }
    }

    return res;
  }

  inline bool isOdd(const int num) { return num & 1; }
};
}  // namespace leetcode
#endif  // LEETCODE_MINIMIZE_DEVIATION_IN_ARRAY_H
