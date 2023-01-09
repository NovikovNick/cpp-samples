#ifndef LEETCODE_MERGE_TWO_SORTED_LISTS_H
#define LEETCODE_MERGE_TWO_SORTED_LISTS_H
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1 && !list2) return nullptr;
    if (!list1 && list2) return list2;
    if (list1 && !list2) return list1;

    ListNode* res_head;
    if (list1->val > list2->val) {
      res_head = list2;
      list2 = list2->next;
    } else {
      res_head = list1;
      list1 = list1->next;
    }

    ListNode* curr = res_head;
    while (list1 && list2) {
      if (list1->val > list2->val) {
        curr->next = list2;
        list2 = list2->next;
      } else {
        curr->next = list1;
        list1 = list1->next;
      }
      curr = curr->next;
    }

    if (!list1 && list2)
      curr->next = list2;
    else
      curr->next = list1;

    return res_head;
  }

  void print(ListNode* lst) {
    while (lst) {
      debug("{} ", lst->val);
      lst = lst->next;
    }
    debug("\n");
  }
};
}  // namespace leetcode
#endif  // LEETCODE_MERGE_TWO_SORTED_LISTS_H
