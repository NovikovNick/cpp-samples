#ifndef LEETCODE_STICKERS_TO_SPELL_WORD_H
#define LEETCODE_STICKERS_TO_SPELL_WORD_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
using namespace std;

struct Wrapper {
  std::vector<int> letters;
  int length = 0;

  Wrapper(std::vector<int> letters, int length)
      : letters(letters), length(length) {}

  Wrapper(const std::string& str)
      : length(str.size()), letters(std::vector<int>(26)) {
    for (auto ch : str) ++letters[static_cast<int>(ch) - static_cast<int>('a')];
  }

  const Wrapper operator-(const Wrapper& rv) const {
    std::vector<int> newLetters = letters;
    int length = 0;
    for (int i = 0; i < rv.letters.size(); ++i) {
      newLetters[i] = std::max(newLetters[i] - rv.letters[i], 0);
      length += newLetters[i];
    }
    return Wrapper(newLetters, length);
  }

  std::string ToString() {
    std::string res;
    for (int i = 0; auto count : letters) {
      if (count != 0)
        res += std::string(count, static_cast<char>(static_cast<int>('a') + i));
      ++i;
    }
    return res;
  }
};

using PAIR = std::pair<int, Wrapper>;

class Solution {
 public:
  int minStickers(vector<string>& stickers, string target) {
    // dynamic programming for memorisation
    std::unordered_map<std::string, int> dp;

    std::vector<Wrapper> wrappedStickers;
    std::transform(stickers.begin(), stickers.end(),
                   std::back_inserter(wrappedStickers),
                   [](const std::string& str) { return Wrapper(str); });

    auto comp = [](const PAIR& o1, const PAIR& o2) {
      return o1.first > o2.first;
    };
    std::priority_queue<PAIR, std::vector<PAIR>, decltype(comp)> queue(comp);
    queue.push(std::make_pair(0, Wrapper(target)));

    while (!queue.empty()) {
      auto [count, wrapper] = queue.top();
      queue.pop();

      // std::cout << std::format("Checking count {} - {}({})\n", count, wrapper.ToString(), wrapper.length);

      for (auto sticker : wrappedStickers) {
        auto diff = wrapper - sticker;
        if (diff.length == 0) {
          return count + 1;
        } else if (diff.length < wrapper.length) {
          auto str = diff.ToString();
          if (dp.find(str) == dp.end() || dp[str] > count + 1) {
            dp[str] = count + 1;
            queue.push(std::make_pair(count + 1, diff));
          }
        }
      }
    }
    return -1;
  }
};

}  // namespace leetcode
#endif  // LEETCODE_STICKERS_TO_SPELL_WORD_H
