#ifndef LEETCODE_LONGEST_CYCLE_IN_A_GRAPH_H
#define LEETCODE_LONGEST_CYCLE_IN_A_GRAPH_H
#include <algorithm>
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

struct Cursor {
  int step;
  std::vector<int>& edges_;
  std::vector<std::vector<int>> dsts;
  bool no_circle;
  Cursor(std::vector<int>& edges)
      : edges_(edges),
        step(0),
        no_circle(false),
        dsts(std::vector<std::vector<int>>(2, edges)) {}

  const std::vector<int>& get() const { return dsts[step % 2 == 0]; }

  Cursor& operator++() {
    auto& src = dsts[step % 2 == 0];
    auto& dst = dsts[step % 2 != 0];

    no_circle = true;
    for (int j = 0; j < edges_.size(); ++j) {
      if (src[j] == -1) {
        dst[j] = -1;
      } else {
        dst[j] = edges_[src[j]];
        no_circle = false;
      }
    }
    ++step;
    return *this;
  }

  bool operator!=(const Cursor& rhs) const { return get() != rhs.get(); }
};

class Solution {
 public:
  int longestCycle(vector<int>& edges) {
    Cursor slow(edges), fast(edges);
    int i = 0;
    do {
      debug("{:3d}. ", i);
      print(slow);
      print(fast);

      ++slow;
      ++fast;
      ++fast;
      ++i;
    } while (slow != fast);

    return fast.no_circle ? -1 : i;
  }

  void print(const Cursor& cursor) {
    auto& edges = cursor.get();
    for (const auto& edge : edges) debug("{:3d} ", edge);
    debug("\n");
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LONGEST_CYCLE_IN_A_GRAPH_H
