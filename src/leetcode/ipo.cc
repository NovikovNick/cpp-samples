#ifndef LEETCODE_IPO_H
#define LEETCODE_IPO_H
#include <algorithm>
#include <format>
#include <iostream>
#include <list>
#include <map>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;
using PAIR = std::pair<int, int>;
class Solution {
 public:
  int findMaximizedCapital(int k, int w, vector<int>& profits,
                           vector<int>& capitals) {
    int n = profits.size();
    std::list<PAIR> list;
    for (int i = 0; i < n; ++i) {
      list.push_back({capitals[i], profits[i]});
    }

    auto cmp = [](const PAIR& lhs, const PAIR& rhs) {
      if (lhs.first < rhs.first) return true;
      if (lhs.first == rhs.first) return lhs.second > rhs.second;
      return false;
    };
    list.sort(cmp);

    std::map<int, std::list<PAIR>::iterator> map;
    auto prev = list.begin();
    map[prev->first] = prev;
    for (auto it = std::next(prev); it != list.end(); ++it) {
      if (it->first == prev->first) continue;
      map[it->first] = it;
      prev = it;
    }

    for (int i = 0; i < k; ++i) {
      auto max_pair = list.end();
      for (const auto& [capit, it] : map) {
        if (capit > w) break;
        if (max_pair == list.end() || it->second > max_pair->second)
          max_pair = it;
      }

      if (max_pair == list.end()) return w;

      w += max_pair->second;

      auto next = std::next(max_pair);
      if (next == list.end() || next->first != max_pair->first) {
        map.erase(max_pair->first);
      } else {
        map[next->first] = next;
      }
      list.erase(max_pair);

      /*debug("---- {} \n", w);
      for (const auto& [capit, prof] : list) debug("{}-{}\n", capit, prof);
      for (const auto& [capit, it] : map) debug("{}: {}\n", capit, it->second);*/
    }
    return w;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_IPO_H
