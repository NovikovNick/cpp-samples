#ifndef LEETCODE_WORD_SEARCH_II_H
#define LEETCODE_WORD_SEARCH_II_H
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

struct TrieNode {
  std::vector<TrieNode*> children;
  bool terminate;
  std::string word;

  TrieNode()
      : children(std::vector<TrieNode*>(26, nullptr)),
        terminate(false),
        word("") {}
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    std::vector<std::string> res;
    auto root = BuildTrieTree(words);

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        // debug("\n\nBacktracking [{},{}]: ", i, j);
        DFS(i, j, root, board, std::back_inserter(res));
      }
    }
    std::sort(res.begin(), res.end());
    return res;
  }

 private:
  void DFS(const int i, const int j, TrieNode* node,
           vector<vector<char>>& board,
           std::back_insert_iterator<std::vector<std::string>> out) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
      return;
    }

    char letter = board[i][j];
    if (letter == '#') {
      return;
    }

    int index = letter - 'a';
    // debug("\n#{} Letter {} in {} on [{},{}]. ", depth, letter, word, i, j);

    if (node->children[index] == nullptr) {
      // debug("No such word {}. ", word);
      return;
    }
    auto next = node->children[index];

    if (next->terminate) {
      // debug("Found and remove word - {} -> {}. ", letter, next->word);
      out = next->word;
      ++out;
      next->terminate = false;
    }

    board[i][j] = '#';
    DFS(i + 1, j + 0, next, board, out);
    DFS(i - 1, j + 0, next, board, out);
    DFS(i + 0, j + 1, next, board, out);
    DFS(i + 0, j - 1, next, board, out);
    board[i][j] = letter;
  }

  TrieNode* BuildTrieTree(vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (const auto& word : words) {
      // debug("Adding {} word to tries\n", word);
      TrieNode* curr = root;
      for (const char& letter : word) {
        int index = letter - 'a';
        if (curr->children[index] == nullptr) {
          curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
      }
      curr->terminate = true;
      curr->word = word;
    }
    return root;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_WORD_SEARCH_II_H
