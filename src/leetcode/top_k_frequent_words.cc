#ifndef LEETCODE_TOP_K_FREQUENT_WORDS_H
#define LEETCODE_TOP_K_FREQUENT_WORDS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <queue>
#include <unordered_map>
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
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  vector<string> topKFrequent(vector<string>& words, int k) {
    int n = words.size();
    if (n == k) {
      std::sort(words.begin(), words.end());
      return words;
    };

    std::unordered_map<std::string, int> counts;
    for (const auto& word : words) ++counts[word];

    auto cmp = [&counts = counts](const std::string& lhs,
                                  const std::string& rhs) {
      auto l_count = counts[lhs];
      auto r_count = counts[rhs];
      if (l_count > r_count) return true;
      if (l_count == r_count) return lhs < rhs;
      return false;
    };
    std::priority_queue<std::string, std::vector<std::string>, decltype(cmp)>
        min_heap(cmp);
    for (auto& [word, count] : counts) {
      min_heap.push(word);
      if (min_heap.size() > k) min_heap.pop();
    }

    std::vector<std::string> res(k);
    for (int i = k - 1; i >= 0; --i) {
      res[i] = min_heap.top();
      min_heap.pop();
    }
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_TOP_K_FREQUENT_WORDS_H
