#ifndef LEETCODE_VALID_PARENTHESES_H
#define LEETCODE_VALID_PARENTHESES_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
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
  bool isValid(string s) {
    int n = s.size();
    std::stack<char> stack;

    for (int i = 0; i < n; ++i) {
      switch (s[i]) {
        case ']':
          if (stack.empty() || stack.top() != '[') return false;
          stack.pop();
          break;
        case '}':
          if (stack.empty() || stack.top() != '{') return false;
          stack.pop();
          break;
        case ')':
          if (stack.empty() || stack.top() != '(') return false;
          stack.pop();
          break;
        default:
          stack.push(s[i]);
      }
    }
    return stack.empty();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_VALID_PARENTHESES_H
