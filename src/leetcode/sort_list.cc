#ifndef LEETCODE_SORT_LIST_H
#define LEETCODE_SORT_LIST_H
#include <algorithm>
#include <format>
#include <future>
#include <iostream>
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
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  } 
  ListNode *splice(ListNode *head) {
    auto fast = head;
    ListNode *prev = nullptr;
    while (fast && fast->next) {
      prev = prev == nullptr ? head : prev->next;
      fast = fast->next->next;
    }
    auto mid = prev->next;
    prev->next = nullptr;
    return mid;
  }

  ListNode *merge(ListNode *left, ListNode *right) {
    ListNode dammy;
    ListNode *tail = &dammy;
    while (left && right) {
      if (left->val > right->val) {
        tail->next = right;
        tail = tail->next;
        right = right->next;
      } else {
        tail->next = left;
        tail = tail->next;
        left = left->next;
      }
    }
    if (left && !right) tail->next = left;
    if (!left && right) tail->next = right;
    return dammy.next;
  }

  ListNode *mergesort(ListNode *head) {
    if (!head || !head->next) return head;
    auto mid = splice(head);
    auto left = mergesort(head);
    auto right = mergesort(mid);
    return merge(left, right);
  }

  std::pair<ListNode *, ListNode *> quicksort(ListNode *head) {
    if (!head) return std::make_pair(head, head);
    auto pivot = head;
    head = head->next;

    // partion
    ListNode low_head;
    ListNode *low_tail = &low_head;
    ListNode hight_head;
    ListNode *hight_tail = &hight_head;
    while (head) {
      if (head->val < pivot->val) {
        low_tail->next = head;
        low_tail = low_tail->next;
      } else {
        hight_tail->next = head;
        hight_tail = hight_tail->next;
      }
      head = head->next;
    }
    low_tail->next = nullptr;
    hight_tail->next = nullptr;
    pivot->next = nullptr;

    auto [lb, le] = quicksort(low_head.next);
    auto [hb, he] = quicksort(hight_head.next);

    if (!lb) {
      lb = pivot;
    } else {
      le->next = pivot;
    }

    if (hb) {
      pivot->next = hb;
    } else {
      he = pivot;
    }

    if (he) he->next = nullptr;

    return std::make_pair(lb, he);
  }

  ListNode *sortList(ListNode *head) {
    return mergesort(head);
    // return quicksort(head).first;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_SORT_LIST_H
