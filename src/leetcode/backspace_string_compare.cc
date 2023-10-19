#ifndef LEETCODE_BACKSPACE_STRING_COMPARE_H
#define LEETCODE_BACKSPACE_STRING_COMPARE_H
#include <algorithm>
#include <format>
#include <iostream>
#include <vector>
#include <deque>

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
  bool backspaceCompare(string s, string t) {
    std::deque<char> s_deq;
    for (auto ch : s) {
      if (ch == '#') {
        if (!s_deq.empty()) {
          s_deq.pop_back();
        }
      } else {
        s_deq.push_back(ch);
      }
    }

    std::deque<char> t_deq;
    for (auto ch : t) {
      if (ch == '#') {
        if (!t_deq.empty()) {
          t_deq.pop_back();
        }
      } else {
        t_deq.push_back(ch);
      }
    }

    return t_deq == s_deq;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BACKSPACE_STRING_COMPARE_H
