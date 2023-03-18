#ifndef LEETCODE_DESIGN_BROWSER_HISTORY_H
#define LEETCODE_DESIGN_BROWSER_HISTORY_H
#include <algorithm>
#include <numeric>
#include <format>
#include <iostream>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class BrowserHistory {
  int cursor_;
  std::vector<std::string> history_;

 public:
  BrowserHistory(string homepage)
      : history_(std::vector<std::string>{homepage}), cursor_(0) {}

  void visit(string url) {
    if (cursor_ != history_.size() - 1) history_.resize(cursor_ + 1);
    history_.push_back(url);
    ++cursor_;
  }

  string back(int steps) {
    cursor_ = std::max(0, cursor_ - steps);
    return history_[cursor_];
  }

  string forward(int steps) {
    cursor_ = std::min<int>(history_.size() - 1, cursor_ + steps);
    return history_[cursor_];
  }
};

}  // namespace leetcode
#endif  // LEETCODE_DESIGN_BROWSER_HISTORY_H
