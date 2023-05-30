#ifndef LEETCODE_DESIGN_HASHSET_H
#define LEETCODE_DESIGN_HASHSET_H
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

class MyHashSet {
  std::vector<bool> counts;

 public:
  MyHashSet() : counts(1e6 + 1, false) {}

  void add(int key) { counts[key] = true; }

  void remove(int key) { counts[key] = false; }

  bool contains(int key) { return counts[key]; }
};
}  // namespace leetcode
#endif  // LEETCODE_DESIGN_HASHSET_H
