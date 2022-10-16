#include "tree_printer.h"

#include <algorithm>
#include <bit>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>

namespace {
template <typename NODE>
void print(NODE node, int depth) {
  for (int i = 0; i < depth; ++i) {
    std::cout << "  ";
  }
  std::cout << node->val << std::endl;
  if (node->left != nullptr) {
    print(node->left, depth + 1);
  }
  if (node->right != nullptr) {
    print(node->right, depth + 1);
  }
}

template <typename T>
class Wrapper {
 public:
  T data;
  int level = 0;
  uint8_t index;
  Wrapper() = default;
  Wrapper(T data, int level, int index)
      : data(data), level(level), index(index){};
};

uint64_t getMostSignificantBit(uint8_t i) {
  std::bitset<16> bitset(i);
  std::bitset<16> res = 1;
  while ((bitset >>= 1) != 0) {
    res <<= 1;
  }
  return res.to_ulong();
}
}  // namespace

template <typename NODE>
void util::walkTreeAndPrint(NODE node) {
  Wrapper root(node, 0, 0);

  std::deque<Wrapper<NODE>> deque{root};
  std::vector<Wrapper<NODE>> arr(8);
  int maxLevel = 0;

  // DFS and fill arr
  while (!deque.empty()) {
    auto it = deque.back();
    deque.pop_back();

    auto msb = getMostSignificantBit(it.index) << 1;
    std::cout << std::to_string(it.data->val) << "(" << std::to_string(it.index)
              << ")-";
    if (arr.size() < msb) {
      arr.resize(msb);
    }
    arr[it.index] = it;
    maxLevel = maxLevel > it.level ? maxLevel : it.level;

    if (it.data->right != nullptr) {
      deque.push_back(Wrapper(it.data->right, it.level + 1, it.index * 2 + 2));
    }
    if (it.data->left != nullptr) {
      deque.push_back(Wrapper(it.data->left, it.level + 1, it.index * 2 + 1));
    }
  }
  std::cout << std::endl;

  // draw tree
  int level = 0;
  for (auto i = 1u; auto it : arr) {
    std::string str = (it.data == nullptr)
                          ? "___"
                          : std::to_string(it.data->val) + "(" +
                                std::to_string(it.index) + ") ";

    std::cout << std::setw(maxLevel * 10 - 7 * level) << std::setfill(' ')
              << str;

    if (std::has_single_bit(++i)) {
      ++level;
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}