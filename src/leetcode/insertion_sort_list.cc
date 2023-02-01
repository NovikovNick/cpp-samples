#ifndef LEETCODE_INSERTION_SORT_LIST_H
#define LEETCODE_INSERTION_SORT_LIST_H
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
  /*ListNode* insertionSortList(ListNode* head) {
    auto sentinel = head->next;
    while (sentinel != nullptr) {
      backwardSort(head, sentinel);
      sentinel = sentinel->next;
    }
    return head;
  }

  ListNode* backwardSort(ListNode* begin, ListNode* end) {
    if (begin->next == end) return begin;

    auto next = backwardSort(begin->next, end);
    if (begin->val > next->val) std::swap(begin->val, next->val);
    return begin;
  }*/

  ListNode* insertionSortList(ListNode* head) {
    auto dummy = new ListNode; // !
    
    auto curr = head;
    while (curr != nullptr) {
      auto prev = dummy; // !

      // find place to insert
      while (prev->next != nullptr && prev->next->val < curr->val) {
        prev = prev->next;
      }

      auto next = curr->next; // !

      // insertion
      curr->next = prev->next;
      prev->next = curr;

      curr = next;
    }
    return dummy->next;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_INSERTION_SORT_LIST_H
