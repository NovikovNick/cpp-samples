#ifndef LEETCODE_TEXT_JUSTIFICATION_H
#define LEETCODE_TEXT_JUSTIFICATION_H
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
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    debug("justify text\n");
    return {};
  }
};
}  // namespace leetcode
#endif  // LEETCODE_TEXT_JUSTIFICATION_H
