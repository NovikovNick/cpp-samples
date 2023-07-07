#ifndef LEETCODE_MAXIMIZE_THE_CONFUSION_OF_AN_EXAM_H
#define LEETCODE_MAXIMIZE_THE_CONFUSION_OF_AN_EXAM_H
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
  int maxConsecutiveAnswers(string answerKey, int k) {
    debug("max Consecutive Answers");
    return 42;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MAXIMIZE_THE_CONFUSION_OF_AN_EXAM_H
