#ifndef LEETCODE_SWAP_NODES_IN_PAIRS_H
#define LEETCODE_SWAP_NODES_IN_PAIRS_H
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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* prev_prev = nullptr;
    auto prev = head;
    auto curr = head->next;
    auto next = curr->next;
    head = curr;
    while (curr) {

      if (prev_prev) prev_prev->next = curr;
      curr->next = prev;
      prev->next = next;
      if (!next) return head;

      prev_prev = prev;
      prev = next;
      curr = next->next;
      if (!curr) return head;
      next = curr->next;
    }
    return head;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SWAP_NODES_IN_PAIRS_H
