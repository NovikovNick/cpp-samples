#ifndef LEETCODE_PARTITION_LIST_H
#define LEETCODE_PARTITION_LIST_H
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
  ListNode* partition(ListNode* head, int x) {
    ListNode left;
    ListNode right;

    ListNode* curr_left = &left;
    ListNode* curr = head;
    ListNode* next = head;
    ListNode* curr_right = &right;
    while (curr) {
      next = curr->next;
      curr->next = nullptr;

      if (curr->val < x) {
        curr_left = curr_left->next = curr;
      } else {
        curr_right = curr_right->next = curr;
      }

      curr = next;
    }

    curr_left->next = right.next;

    return left.next;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_PARTITION_LIST_H
