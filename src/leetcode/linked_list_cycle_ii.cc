#ifndef LEETCODE_LINKED_LIST_CYCLE_II_H
#define LEETCODE_LINKED_LIST_CYCLE_II_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_set>
#include <vector>

template <typename... Args>
void debug(const std::string_view &str, Args &&...args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  // brute force
  /*ListNode *detectCycle(ListNode *head) {
    std::unordered_set<ListNode *> set;
    while (head) {
      if (!set.insert(head).second) return head;
      head = head->next;
    }
    return nullptr;
  }*/

  ListNode *detectCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;
    bool cycle = false;
    int count = 0;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (cycle = (slow == fast)) break;
      ++count;
    }
    if (!cycle) return nullptr;

    int cycle_size = 0;
    slow = slow->next;
    while (slow != fast) {
      slow = slow->next;
      ++cycle_size;
    }

    int from_head = 0;
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      ++from_head;
    }
    debug("Detected at: {:2d}. Cycle size: {:2d}. From head: {:2d}", count,
          cycle_size, from_head);
    return head;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LINKED_LIST_CYCLE_II_H
