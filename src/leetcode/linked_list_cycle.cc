#ifndef LEETCODE_LINKED_LIST_CYCLE_H
#define LEETCODE_LINKED_LIST_CYCLE_H
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
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  bool hasCycle(ListNode* head) {
    auto slow = head, fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return true;
    }
    return false;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_LINKED_LIST_CYCLE_H
