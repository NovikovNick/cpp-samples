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

struct Node {
  std::shared_ptr<Node> prev, next;
  int counter;
  int val;
  Node(const int val) : val(val), counter(1), prev(nullptr), next(nullptr) {}
};

class LFUCache {
  int capacity, size;
  std::shared_ptr<Node> tail;
  std::unordered_map<int, std::shared_ptr<Node>> map;

 public:
  LFUCache(int capacity)
      : capacity(capacity),
        size(0),
        tail(nullptr),
        map(std::unordered_map<int, std::shared_ptr<Node>>()) {}

  int get(int key) {
    const auto it = map.find(key);

    if (it == map.end()) {
      return -1;
    } else {
      incrementUsage(it->second);
      return it->second->val;
    }
  }

  void put(int key, int value) {
    if (capacity == 0) return;

    auto [it, inserted] = map.emplace(key, std::make_shared<Node>(value));
    if (inserted) {
      insert(it->second);
    } else {
      if (capacity == 1) return;
      incrementUsage(it->second);
    }
  }

 private:
  void incrementUsage(std::shared_ptr<Node> node) {
    node->counter += 1;
    while (node->next != nullptr && node->next->counter <= node->counter) {
      auto next = node->next;
      auto next_next = next->next;
      auto prev = node->prev;

      node->next = next_next;
      node->prev = next;
      if (next_next != nullptr) next_next->prev = node;

      next->next = node;
      next->prev = prev;
      if (prev != nullptr) prev->next = next;

      if (node == tail) tail = next;
    }
  }

  void insert(std::shared_ptr<Node> node) {
    ++size;
    if (capacity == 1 || tail == nullptr) {
      tail = node;
      return;
    }

    if (tail->counter > 1) {
      tail->prev = node;
      node->next = tail;
      tail = node;
    } else {
      auto curr = tail;
      while (curr->next != nullptr && curr->counter <= node->counter) {
        curr = curr->next;
      }
      if (curr->counter <= node->counter) {
        curr->next = node;
        node->prev = curr;
      } else {
        node->prev = curr->prev;
        curr->prev = node;
        node->next = curr;
      }
    }

    if (size > capacity) {
      map.erase(tail->val);
      tail = tail->next;
      tail->prev = nullptr;
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LFU_CACHE_H
