#ifndef LEETCODE_REVERSE_LINKED_LIST_II_H
#define LEETCODE_REVERSE_LINKED_LIST_II_H
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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy;
    dummy.next = head;

    ListNode* leftNodePrev = &dummy;
    ListNode* leftNode = dummy.next;
    ListNode* rightNode = dummy.next;
    ListNode* rightNodeNext = nullptr;

    for (int i = 1; i <= right; ++i) {
      if (i < left) leftNodePrev = rightNode;
      if (i == left) leftNode = rightNode;
      if (i != right) rightNode = rightNode->next;
    }
    rightNodeNext = rightNode->next;
    
    leftNodePrev->next = rightNode;
    reverse(leftNode, rightNodeNext);
    leftNode->next = rightNodeNext;

    return dummy.next;
  }

  void reverse(ListNode* begin, ListNode* end) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    while (begin != end) {

      next = begin->next;

      begin->next = prev;// change direction

      prev = begin;
      begin = next;

      // next = std::exchange(begin->next, prev);
      // prev = std::exchange(begin, next);
    }

  }

  // bruteforce solution
  /*ListNode* reverseBetween(ListNode* head, int left, int right) {
    std::vector<int> values;
    ListNode* curr = head;
    while (curr) {
      values.push_back(curr->val);
      curr = curr->next;
    }

    std::reverse(values.begin() + left - 1, values.begin() + right - 1);

    ListNode* curr = head;
    for (const auto val : values) {
      curr->val = val;
      curr = curr->next;
    }
    return head;
  }*/
};
}  // namespace leetcode
#endif  // LEETCODE_REVERSE_LINKED_LIST_II_H
