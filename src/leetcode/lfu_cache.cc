#ifndef LEETCODE_LFU_CACHE_H
#define LEETCODE_LFU_CACHE_H
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

class LFUCache {
  using KEY = int;
  using VAL = int;
  using FREQUENCY = uint32_t;
  using KEY_VAL = std::pair<KEY, VAL>;

  std::unordered_map<FREQUENCY, std::list<std::pair<KEY, VAL>>> frequencies;
  std::unordered_map<KEY, std::pair<FREQUENCY, list<KEY_VAL>::iterator>> cache;
  int min_freq, capacity;

 public:
  LFUCache(int capacity) : capacity(capacity), min_freq(0) {}

  int get(KEY key) {
    auto it = cache.find(key);
    if (it == cache.end()) return -1;

    auto freq = it->second.first;
    auto iter = it->second.second;
    auto [k, val] = *iter;

    frequencies[freq].erase(iter);
    if (frequencies[freq].empty() && min_freq == freq) ++min_freq;
    insert(key, freq + 1, val);

    return val;
  }

  void put(KEY key, VAL value) {
    if (capacity == 0) return;

    auto it = cache.find(key);
    if (it == cache.end()) {

      if (cache.size() == capacity) {
        auto min_key = frequencies[min_freq].front().first;
        frequencies[min_freq].pop_front();
        cache.erase(key);
      }

      min_freq = 1;
      insert(key, 1, value);

    } else {
      it->second.second->second = value;
      get(key);
    }
  }

 private:
  void insert(KEY key, FREQUENCY freq, VAL val) {
    frequencies[freq].emplace_back(key, val);
    cache[key] = {freq, std::prev(frequencies[freq].end())};
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LFU_CACHE_H
