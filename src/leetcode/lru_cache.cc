#ifndef LEETCODE_LRU_CACHE_H
#define LEETCODE_LRU_CACHE_H
#include <algorithm>
#include <format>
#include <iostream>
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

class LRUCache {
  using LIST = std::list<std::pair<int, int>>;
  using ITERATOR = std::list<std::pair<int, int>>::iterator;
  int capacity;
  std::unordered_map<int, ITERATOR> data;
  LIST freq;

 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    if (!contains(key)) return -1;

    auto it = data[key];
    freq.splice(freq.begin(), freq, it);
    return (*it).second;
  }

  void put(int key, int value) {
    if (contains(key)) {
      auto it = data[key];
      freq.splice(freq.begin(), freq, it);
      (*it).second = value;
    } else {
      freq.push_front({key, value});
      data[key] = freq.begin();
      if (freq.size() > capacity) {
        data.erase(freq.back().first);
        freq.pop_back();
      }
    }
  }

  inline bool contains(const int key) { return data.find(key) != data.end(); }
};
}  // namespace leetcode
#endif  // LEETCODE_LRU_CACHE_H
