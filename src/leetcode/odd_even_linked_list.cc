#ifndef LEETCODE_ODD_EVEN_LINKED_LIST_H
#define LEETCODE_ODD_EVEN_LINKED_LIST_H
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
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
      return head;

    auto odd_head = head;
    auto even_tail = head->next;
    auto even_head = head->next;
    auto curr = head->next->next;
    bool even = false;
    while (curr != nullptr) {
      if (even) {
        even_head->next = curr;
        even_head = curr;
      } else {
        odd_head->next = curr;
        odd_head = curr;
      }
      curr = curr->next;
      even = !even;

      debug("odd_tail = {}, odd_head = {}, even_tail = {}, even_head = {}\n",
            head->val, odd_head->val, even_tail->val, even_head->val);
    }

    odd_head->next = even_tail;
    even_head->next = nullptr;
    return head;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_ODD_EVEN_LINKED_LIST_H
