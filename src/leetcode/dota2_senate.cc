#ifndef LEETCODE_DOTA2_SENATE_H
#define LEETCODE_DOTA2_SENATE_H
#include <algorithm>
#include <format>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

template <typename... Args>
void debug(const std::string_view& str, Args&&... args) {
#if DEBUG
  std::cout << std::vformat(str, std::make_format_args(args...));
#endif
}

namespace leetcode {

using namespace std;

class Solution {
  std::string kRadiant{"Radiant"};
  std::string kDire{"Dire"};

 public:
  /*string predictPartyVictory(string senate) {
    std::stack<int> radiant_indexes, dire_indexes;

    for (int i = senate.size() - 1; i >= 0; --i) {
      (senate[i] == 'R' ? radiant_indexes : dire_indexes).push(i);
    }

    int i = 0;
    while (!radiant_indexes.empty() && !dire_indexes.empty()) {
      if (senate[i] != '#') {
        if (senate[i] == 'R') {
          senate[dire_indexes.top()] = '#';
          dire_indexes.pop();
        } else {
          senate[radiant_indexes.top()] = '#';
          radiant_indexes.pop();
        }
      }
      ++i;
      i %= senate.size();
    }

    return radiant_indexes.empty() ? dire : radiant;
  }*/

  string predictPartyVictory(string senate) {
    std::list<int> radiant, dire;

    for (int i = 0; i < senate.size(); ++i) {
      (senate[i] == 'R' ? radiant : dire).push_back(i);
    }

    auto radiant_iter = radiant.begin();
    auto dire_iter = dire.begin();

    int i = 0;
    while (!radiant.empty() && !dire.empty()) {
      if (senate[i] != '#') {
        if (senate[i] == 'R') {
          senate[*dire_iter] = '#';
          dire.erase(dire_iter++);
        } else {
          senate[*radiant_iter] = '#';
          radiant.erase(radiant_iter++);
        }
        if (dire_iter == dire.end()) dire_iter = dire.begin();
        if (radiant_iter == radiant.end()) radiant_iter = radiant.begin();
      }
      ++i;
      i %= senate.size();
    }

    return radiant.empty() ? kDire : kRadiant;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_DOTA2_SENATE_H
