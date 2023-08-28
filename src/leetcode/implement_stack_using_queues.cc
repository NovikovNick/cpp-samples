#ifndef LEETCODE_IMPLEMENT_STACK_USING_QUEUES_H
#define LEETCODE_IMPLEMENT_STACK_USING_QUEUES_H
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

class MyStack {
  std::queue<int> q;

 public:
  MyStack() {}

  void push(int x) {
    q.push(x);
  }

  int pop() {
    int size = q.size();
    while (--size > 0) roll();
    int res = q.front();
    q.pop();
    return res;
  }

  int top() {
    int size = q.size();
    while (--size > 0) roll();
    int res = q.front();
    q.pop();
    q.push(res);
    return res;
  }

  bool empty() { return q.empty(); }

 private:
  void roll() {
    q.push(q.front());
    q.pop();
  }
};
}  // namespace leetcode
#endif  // LEETCODE_IMPLEMENT_STACK_USING_QUEUES_H
