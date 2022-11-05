#ifndef LEETCODE_WORD_SEARCH_II_H
#define LEETCODE_WORD_SEARCH_II_H
#include <algorithm>
#include <format>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace leetcode {

using namespace std;

struct Grid {
  using Cell = std::pair<int, int>;
  struct CellHash {
    size_t operator()(const Cell& o) const {
      auto h1 = std::hash<int>{}(o.first);
      auto h2 = std::hash<int>{}(o.second);
      return h1 == h2 ? h1 : h1 ^ h2;
    }
  };
  struct CellEquals {
    bool operator()(const Cell& o1, const Cell& o2) const {
      return o1.first == o2.first && o1.second == o2.second;
    }
  };

  using LetterCoords = std::unordered_map<char, std::vector<Cell>>;

  std::vector<std::vector<char>> board;
  int width, height;
  LetterCoords letter_coords;

  Grid(vector<vector<char>>& board)
      : board(board),
        height(board.size()),
        width(board[0].size()),
        letter_coords(InitLetters(board)) {}

  void Print() {
    for (int y = 0; y < height; ++y) {
      for (int x = 0; x < width; ++x) {
        std::cout << std::format("{}[{},{}] ", board[y][x], x, y);
      }
      std::cout << std::endl;
    }

    for (auto [letter, coords] : letter_coords) {
      std::cout << std::format("{}: ", letter);
      for (auto [x, y] : coords) {
        std::cout << std::format("[{},{}] ", x, y);
      }
      std::cout << std::endl;
    }
  };

  bool Contains(const std::string& word) {
    auto it = letter_coords.find(word[0]);
    if (it == letter_coords.end()) {
      return false;
    }
    for (auto cell : it->second) {
      if (word.size() == 1 || Contains(cell, word)) {
        return true;
      }
    }
    return false;
  };

 private:
  LetterCoords InitLetters(const std::vector<std::vector<char>>& board) {
    LetterCoords res;
    for (int y = 0; y < height; ++y) {
      for (int x = 0; x < width; ++x) {
        res[board[y][x]].push_back(Cell(x, y));
      }
    }
    return res;
  };
  bool Contains(const Cell head, const std::string& word) {
    std::unordered_set<Cell, CellHash, CellEquals> exp(32, CellHash(),
                                                            CellEquals());
    exp.insert(head);
    std::stack<
        std::tuple<Cell, int, std::unordered_set<Cell, CellHash, CellEquals>>>
        reachable;
    reachable.push(std::make_tuple(head, 0, exp));
    
    while (!reachable.empty()) {
      auto [cell, index, explored] = reachable.top();
      reachable.pop();

      for (auto adjacent : FindAdjacent(cell)) {
        auto [x, y] = adjacent;
        if (explored.find(adjacent) != explored.end()) {
          //std::cout << std::format("adjacent [{},{}] explored\n", x, y);
          continue;
        }
        if (board[y][x] == word[index + 1]) {
          //std::cout << std::format("adjacent [{},{}] ", x, y);
          if (word.size() == index + 2) {
            //std::cout << std::format("is last! ");
            return true;
          } else {
            //std::cout << std::format("not last. Continue search...\n");
            auto explored_copy = explored;
            explored_copy.insert(adjacent);
            reachable.push(std::make_tuple(adjacent, index + 1, explored_copy));
          }
        }
      }
      explored.insert(cell);
    }
    return false;
  }
  std::vector<Cell> FindAdjacent(const Cell& cell) {
    auto [x, y] = cell;
    std::vector<Cell> res;
    if ((x - 1) >= 0) res.push_back(Cell(x - 1, y));
    if ((x + 1) < width) res.push_back(Cell(x + 1, y));
    if ((y - 1) >= 0) res.push_back(Cell(x, y - 1));
    if ((y + 1) < height) res.push_back(Cell(x, y + 1));
    return res;
  };
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Grid grid(board);
    grid.Print();

    std::vector<std::string> res;
    for (auto word : words) {
      //std::cout << std::format("Checking {}\n", word);
      if (grid.Contains(word)) {
        res.push_back(word);
        //std::cout << std::format("There is {} on the board\n", word);
      } else {
        //std::cout << std::format("NO {} on the board\n", word);
      }
    }
    std::sort(res.begin(), res.end());
    return res;
  }
};
}  // namespace leetcode
#endif  // LEETCODE_WORD_SEARCH_II_H
