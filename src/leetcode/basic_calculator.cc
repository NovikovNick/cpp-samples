#ifndef LEETCODE_BASIC_CALCULATOR_H
#define LEETCODE_BASIC_CALCULATOR_H
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
  using int_t = int32_t;

  std::stack<std::string> stack_;

 public:
  Solution() : stack_(std::stack<std::string>()) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int calculate(std::string s) {
    int n = s.size();

    for (int i = 0; i < n; ++i) {
      if (std::isdigit(s[i])) {
        // parse operand
        int_t operand = 0;
        while (i < n && std::isdigit(s[i])) {
          operand = operand * 10 + (s[i] - '0');
          ++i;
        }
        EvalOperand(operand);
      }

      if (s[i] == ')') {
        CollapseBracers();
        continue;
      }

      if (s[i] == ' ') continue;
      if (s[i] == '(' || s[i] == '+' || s[i] == '-')
        stack_.push(std::string{s[i]});
    }

    return std::stol(stack_.top());
  }

  void CollapseBracers() {
    int_t operand = std::stoi(stack_.top());
    stack_.pop();
    stack_.pop();
    EvalOperand(operand);
  }

  void EvalOperand(int_t operand) {
    while (!stack_.empty() && stack_.top() != "(") {
      auto str = stack_.top();
      if (str == "-") {
        operand = -operand;
      } else if (std::isdigit(str[str.size() - 1])) {
        operand = std::stol(str) + operand;
      }
      stack_.pop();
    }
    stack_.push(std::to_string(operand));
  }
};
}  // namespace leetcode
#endif  // LEETCODE_BASIC_CALCULATOR_H
