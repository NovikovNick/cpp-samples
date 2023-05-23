#ifndef LEETCODE_KTH_LARGEST_ELEMENT_IN_A_STREAM_H
#define LEETCODE_KTH_LARGEST_ELEMENT_IN_A_STREAM_H
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

class KthLargest {
  using MIN_HEAP = std::priority_queue<int, std::vector<int>, std::greater<int>>;
  MIN_HEAP min_heap;
  int k;

 public:
  KthLargest(int k, vector<int>& nums)
      : k(k), min_heap(MIN_HEAP(nums.begin(), nums.end())) {
    while (min_heap.size() > k) min_heap.pop();
  }

  int add(int val) {
    min_heap.push(val);
    if (min_heap.size() > k) min_heap.pop();
    return min_heap.top();
  }
};

}  // namespace leetcode
#endif  // LEETCODE_KTH_LARGEST_ELEMENT_IN_A_STREAM_H
