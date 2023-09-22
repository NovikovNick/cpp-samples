#ifndef LEETCODE_DESIGN_HASHMAP_H
#define LEETCODE_DESIGN_HASHMAP_H
#include <algorithm>
#include <format>
#include <iostream>
#include <list>
#include <vector>
#include <optional>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class MyHashMap {
  static const size_t k_bucket_count = 32;

  using KEY = int;
  using VALUE = int;
  using PAIR = std::pair<KEY, VALUE>;
  std::hash<KEY> hasher_;
  std::vector<std::list<PAIR>> buckets_;

 public:
  MyHashMap()
      : hasher_(std::hash<KEY>()),  //
        buckets_(std::vector<std::list<PAIR>>(k_bucket_count)) {}

  void put(KEY key, VALUE value) {
    auto& bucket = buckets_[hasher_(key) % k_bucket_count];

    for (auto& [k, val] : bucket) {
      if (key == k) {
        val = value;
        return;
      }
    }
    bucket.push_back(std::make_pair(key, value));
  }

  int get(KEY key) {
    auto& bucket = buckets_[hasher_(key) % k_bucket_count];
    for (const auto& [k, val] : bucket) {
      if (key == k) return val;
    }
    return -1;
  }

  void remove(KEY key) {
    auto& bucket = buckets_[hasher_(key) % k_bucket_count];
    bucket.remove_if([key](const auto& pair) { return pair.first == key; });
    // std::erase_if(bucket, [key](const auto& pair) { return pair.first == key; });
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DESIGN_HASHMAP_H
