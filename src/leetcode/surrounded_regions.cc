#ifndef LEETCODE_SURROUNDED_REGIONS_H
#define LEETCODE_SURROUNDED_REGIONS_H
#include <algorithm>
#include <format>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

struct Group {
  int parent, size;
  bool border;
  char type;
  Group() : parent(0), size(1), border(false), type('X') {}
};
class Solution {
  int n, m;

 public:
  Solution() : n(0), m(0) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    wcin.tie(nullptr);
    cerr.tie(nullptr);
    wcerr.tie(nullptr);
    clog.tie(nullptr);
    wclog.tie(nullptr);
  }
  void solve(vector<vector<char>>& board) {
    n = board.size();
    m = board[0].size();
    std::vector<Group> groups(n * m);

    for (int row = 0, i; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        i = row * m + col;

        auto& group = groups[i];
        group.parent = i;
        group.size = 1;
        group.border = isLftBorder(col) || isRhtBorder(col) ||
                       isTopBorder(row) || isBtmBorder(row);
        group.type = board[row][col];
      }
    }

    for (int row = 0, i; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        i = row * m + col;
        if (!isLftBorder(col)) {
          check(i, row * m + (col - 1), groups);
          //print(i, groups);
        }
        if (!isRhtBorder(col)) {
          check(i, row * m + (col + 1), groups);
          //print(i, groups);
        }
        if (!isTopBorder(row)) {
          check(i, (row - 1) * m + col, groups);
          //print(i, groups);
        }
        if (!isBtmBorder(row)) {
          check(i, (row + 1) * m + col, groups);
          //print(i, groups);
        }
      }
    }

    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        if (!groups[findParent(row * m + col, groups)].border)
          board[row][col] = 'X';
      }
    }
  }

  /*void print(const int i, std::vector<Group>& groups) {
    debug("{}. groups:\n", i);
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        auto i = row * m + col;
        debug("{:2d}({:2d}){} ", groups[i].parent, groups[i].size,
              groups[i].border ? "*" : " ");
      }
      debug("\n");
    }
  }*/

  int findParent(int index, std::vector<Group>& groups) {
    auto group = groups[index];
    while (group.parent != index) group = groups[index = group.parent];
    return index;
  }

  inline bool isLftBorder(const int col) { return col == 0; }
  inline bool isRhtBorder(const int col) { return col == (m - 1); }
  inline bool isTopBorder(const int row) { return row == 0; }
  inline bool isBtmBorder(const int row) { return row == (n - 1); }

  inline void merge(const int from, const int into,
                    std::vector<Group>& groups) {
    groups[into].size += groups[from].size;
    groups[from].parent = into;
    groups[from].size = 0;

    groups[from].border = groups[from].border || groups[into].border;
    groups[into].border = groups[from].border;
  }

  void check(const int group_index, const int adj_index,
             std::vector<Group>& groups) {
    auto& adj = groups[adj_index];

    if (adj.type != groups[group_index].type) return;

    auto group_parent_index = findParent(group_index, groups);
    auto& group_parent = groups[group_parent_index];

    if (adj_index == group_parent_index) return;

    if (adj.parent == adj_index) {
      adj.parent = group_parent_index;
      ++group_parent.size;

      group_parent.border = adj.border = group_parent.border || adj.border;

    } else if (adj.parent != group_parent_index) {
      auto adj_parent_index = findParent(adj_index, groups);
      auto& adj_parent = groups[adj_parent_index];

      if (adj_parent.border || adj_parent.size > group_parent.size) {
        merge(group_parent_index, adj_parent_index, groups);
      } else {
        merge(adj_parent_index, group_parent_index, groups);
      }
    }
  };
};
}  // namespace leetcode
#endif  // LEETCODE_SURROUNDED_REGIONS_H
