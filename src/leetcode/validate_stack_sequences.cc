#ifndef LEETCODE_VALIDATE_STACK_SEQUENCES_H
#define LEETCODE_VALIDATE_STACK_SEQUENCES_H
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
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int pushed_cursor = 0, popped_cursor = 0, n = pushed.size();
    std::stack<int> stack;

    while (popped_cursor < n) {
      if (!stack.empty() && stack.top() == popped[popped_cursor]) {
        stack.pop();
        ++popped_cursor;
      } else if (pushed_cursor < n) {
        stack.push(pushed[pushed_cursor]);
        ++pushed_cursor;
      } else {
        return false;
      }
    }
    return true;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_VALIDATE_STACK_SEQUENCES_H
