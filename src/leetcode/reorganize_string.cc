#ifndef LEETCODE_REORGANIZE_STRING_H
#define LEETCODE_REORGANIZE_STRING_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <queue>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class Solution {
  const int k_ASCII_size = 128;
  std::vector<int> counts;

 public:
  Solution() : counts(std::vector<int>(k_ASCII_size, 0)){};
  string reorganizeString(string s) {
    for (const auto letter : s) ++counts[static_cast<int>(letter)];

    std::priority_queue<std::pair<int, char>> max_heap;
    
    for (int i = 0; i < k_ASCII_size; ++i) {
      if (auto count = counts[i]; count != 0) {
        max_heap.push({count, i});
      }
    }

    int i = 0;
    std::pair<int, char> prev{0, 0};
    while (!max_heap.empty()) {
      auto [count, letter] = max_heap.top();
      max_heap.pop();

      s[i++] = letter;

      if(prev.first > 0) max_heap.push(prev);
      prev.first = count - 1;
      prev.second = letter;
    }
    return prev.first ? "" : s;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REORGANIZE_STRING_H
