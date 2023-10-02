#ifndef LEETCODE_REMOVE_COLORED_PIECES_IF_BOTH_NEIGHBORS_ARE_THE_SAME_COLOR_H
#define LEETCODE_REMOVE_COLORED_PIECES_IF_BOTH_NEIGHBORS_ARE_THE_SAME_COLOR_H
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
  bool winnerOfGame(string colors) {
    int movesA = 0;
    int movesB = 0;

    int seqA = 0;
    int seqB = 0;
    for (int i = 0; i < colors.size(); ++i) {
      if (colors[i] == 'A') {
        seqB = 0;
        ++seqA;
        if (seqA > 2) ++movesA;
      } else {
        seqA = 0;
        ++seqB;
        if (seqB > 2) ++movesB;
      }
    }

    return movesA > movesB;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REMOVE_COLORED_PIECES_IF_BOTH_NEIGHBORS_ARE_THE_SAME_COLOR_H
