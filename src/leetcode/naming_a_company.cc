#ifndef LEETCODE_NAMING_A_COMPANY_H
#define LEETCODE_NAMING_A_COMPANY_H
#include <algorithm>
#include <format>
#include <iostream>
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

const static int alphabet_count = 26;

class Trie {
 public:
  struct Node {
    std::vector<std::shared_ptr<Node>> children;
    bool is_word;
    Node()
        : children(std::vector<std::shared_ptr<Node>>(alphabet_count)),
          is_word(false){};
  };

  std::shared_ptr<Node> root;

  Trie() : root(std::make_shared<Node>()){};

  void add(const std::string& word) {
    auto curr = root;
    for (const auto& ch : word) {
      if (curr->children[ch - 'a'] == nullptr) {
        curr->children[ch - 'a'] = std::make_shared<Node>();
      }
      curr = curr->children[ch - 'a'];
    }
    curr->is_word = true;
  }

  void counts(const std::string& word,
              std::vector<std::vector<long long>>& unique_counts) {
    int fst_letter = word[0] - 'a';
    for (int i = 0; i < alphabet_count; ++i) {
      auto node = root->children[i];
      if (node == nullptr || fst_letter == i) continue;

      bool unique = false;
      for (int j = 1; j < word.size(); ++j) {
        node = node->children[word[j] - 'a'];
        if (node == nullptr) {
          unique = true;
          break;
        };
      }
      if (unique || !node->is_word) ++unique_counts[fst_letter][i];
    }
  }
};

class Solution {
 public:
  long long distinctNamesTries(vector<string>& ideas) {
    Trie trie;
    for (const auto& idea : ideas) trie.add(idea);

    std::vector<std::vector<long long>> unique_counts(
        alphabet_count, std::vector<long long>(alphabet_count, 0));

    for (const auto& idea : ideas) {
      trie.counts(idea, unique_counts);
    }

    long long res = 0;
    for (int row = 0; row < alphabet_count; ++row) {
      for (int col = 0; col < alphabet_count; ++col) {
        res += unique_counts[row][col] * unique_counts[col][row];
      }
    }
    return res;
  }

  long long distinctNames(vector<string>& ideas) {
    std::vector<std::unordered_set<std::string>> dp(26);
    return 1;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_NAMING_A_COMPANY_H
