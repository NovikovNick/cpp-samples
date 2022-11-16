#ifndef LEETCODE_GUESS_NUMBER_HIGHER_OR_LOWER_H
#define LEETCODE_GUESS_NUMBER_HIGHER_OR_LOWER_H
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

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 *
 */

class Solution {
 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  int guessNumber(int n) {
    int min = 1, max = n, mid, attempt;

    do {
      mid = min + (max - min) / 2;
      debug("{:3d} ? {:3d} = {:3d}\n", min, max, mid);
      attempt = guess(mid);
      if (attempt > 0) {
        min = mid + 1;
      } else if (attempt < 0) {
        max = mid - 1;
      } else {
        return mid;
      }
    } while (max >= min);

    return mid;
  }

  int guess(int num) {
    int pick = 42;
    if (num > pick) return -1;
    return num == pick ? 0 : 1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_GUESS_NUMBER_HIGHER_OR_LOWER_H
