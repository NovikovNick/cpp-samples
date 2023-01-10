#ifndef LEETCODE_REVERSE_LINKED_LIST_H
#define LEETCODE_REVERSE_LINKED_LIST_H
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
  ListNode* new_root = nullptr;
  ListNode* reverse(ListNode* curr) {
    if (!curr->next) {
      new_root = curr;
    } else {
      auto next = reverse(curr->next);
      next->next = curr;
    }
    return curr;
  }

  /*ListNode* reverseList(ListNode* head) {
    if (!head) return head;
    reverse(head)->next = nullptr;
    return new_root;
  }*/

  ListNode* reverseList(ListNode* head) {
    ListNode* temp = head;
    ListNode* prev = nullptr;
    ListNode* next;

    while (temp) {
      next = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next;
    }
    return prev;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_REVERSE_LINKED_LIST_H
