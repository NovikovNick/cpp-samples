#ifndef LEETCODE_SMALLEST_NUMBER_IN_INFINITE_SET_H
#define LEETCODE_SMALLEST_NUMBER_IN_INFINITE_SET_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
#include <vector>
#include <set>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class SmallestInfiniteSet {
  int cursor_;
  std::set<int> set;

 public:
  SmallestInfiniteSet() : cursor_(1) {}

  int popSmallest() {
    int res = cursor_;

    if (!set.empty()) {
      res = *set.begin(); 
      set.extract(res);
    } else {
      ++cursor_;
    }

    return res;
  }

  void addBack(int num) {
    if (num < cursor_) set.insert(num);
  }
};

}  // namespace leetcode
#endif  // LEETCODE_SMALLEST_NUMBER_IN_INFINITE_SET_H
