#ifndef LEETCODE_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define LEETCODE_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
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
 public:
  int lengthOfLongestSubstring(string s) {
    std::vector<int> hash(256);
    std::queue<int> queue;
    int res = 0;
    for (const auto& ch : s) {
      queue.push(ch);
      ++hash[ch];
      if (hash[ch] == 1) {
        res = std::max<int>(res, queue.size());
      } else {
        while (hash[ch] != 1) {
          --hash[queue.front()];
          queue.pop();
        }
      }
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
