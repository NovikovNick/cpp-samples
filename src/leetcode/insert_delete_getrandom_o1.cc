#ifndef LEETCODE_INSERT_DELETE_GETRANDOM_O1_H
#define LEETCODE_INSERT_DELETE_GETRANDOM_O1_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_set>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class RandomizedSet final {
 public:
  std::unordered_set<int> set;

  RandomizedSet() : set(std::unordered_set<int>()) {}

  bool insert(int val) { return set.insert(val).second; }

  bool remove(int val) { return set.erase(val); }

  int getRandom() {
    int distance = std::rand() % set.size();
    auto it = set.begin();
    while (--distance >= 0) ++it;
    return *it;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_INSERT_DELETE_GETRANDOM_O1_H
