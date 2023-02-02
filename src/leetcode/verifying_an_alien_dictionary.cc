#ifndef LEETCODE_VERIFYING_AN_ALIEN_DICTIONARY_H
#define LEETCODE_VERIFYING_AN_ALIEN_DICTIONARY_H
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

class Solution {
 public:
  bool isAlienSorted(vector<string>& words, string order) {
    std::vector<int> order_hash(26);
    for (int i = 0; i < order.size(); ++i) order_hash[order[i] - 'a'] = i;

    auto comparator = [order_hash = order_hash](const std::string& lhs,
                                                const std::string& rhs) {
      for (int i = 0; i < std::min(lhs.size(), rhs.size()); ++i) {
        if (order_hash[lhs[i] - 'a'] < order_hash[rhs[i] - 'a']) return true;
        if (order_hash[lhs[i] - 'a'] > order_hash[rhs[i] - 'a']) return false;
      }
      return lhs.size() < rhs.size();
    };

    return std::is_sorted(words.begin(), words.end(), comparator);
  }
};
}  // namespace leetcode
#endif  // LEETCODE_VERIFYING_AN_ALIEN_DICTIONARY_H
