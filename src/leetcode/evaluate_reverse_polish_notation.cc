#ifndef LEETCODE_EVALUATE_REVERSE_POLISH_NOTATION_H
#define LEETCODE_EVALUATE_REVERSE_POLISH_NOTATION_H
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
  using num = long long;

 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int evalRPN(vector<string>& tokens) {
    std::stack<num> stack;
    for (const auto& token : tokens) {
      switch (token[token.size() - 1]) {
        case '+': {
          auto [a, b] = extractLastTwo(stack);
          stack.push(a + b);
          break;
        }
        case '-': {
          auto [a, b] = extractLastTwo(stack);
          stack.push(a - b);
          break;
        }

        case '/': {
          auto [a, b] = extractLastTwo(stack);
          stack.push(a / b);
          break;
        }
        case '*': {
          auto [a, b] = extractLastTwo(stack);
          stack.push(a * b);
          break;
        }
        default:
          stack.push(std::stoi(token));
      }
    }
    return stack.top();
  }

  pair<num, num> extractLastTwo(std::stack<num>& stack) {
    auto b = stack.top();
    stack.pop();
    auto a = stack.top();
    stack.pop();
    return std::make_pair(a, b);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_EVALUATE_REVERSE_POLISH_NOTATION_H
