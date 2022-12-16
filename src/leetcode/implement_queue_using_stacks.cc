#ifndef LEETCODE_IMPLEMENT_QUEUE_USING_STACKS_H
#define LEETCODE_IMPLEMENT_QUEUE_USING_STACKS_H
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

class MyQueue {
  std::stack<int> fst, snd;
  void load(std::stack<int>& from, std::stack<int>& to) {
    while (!from.empty()) {
      to.push(from.top());
      from.pop();
    }
  }

 public:
  MyQueue() : fst(std::stack<int>()), snd(std::stack<int>()) {}

  void push(int x) {
    load(fst, snd);
    snd.push(x);
    load(snd, fst);
  }

  int pop() {
    int res = fst.top();
    fst.pop();
    return res;
  }

  int peek() { return fst.top(); }

  bool empty() { return fst.empty(); }
};

}  // namespace leetcode
#endif  // LEETCODE_IMPLEMENT_QUEUE_USING_STACKS_H
