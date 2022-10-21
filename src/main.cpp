#include <algorithm>
#include <bit>
#include <bitset>
#include <format>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "a_star.h"

void printGrid() {
  int width = 4, height = 4;

  mysamples::Grid2d<int> grid(width, height);
  std::iota(grid.begin(), grid.end(), 10);

  std::ostream_iterator<int> os(std::cout, " ");
  for (int x = 0; x < width; ++x) {
    std::copy_n(grid.fbegin(0, x), height, os);
    std::cout << std::endl;
  }
  std::cout << std::endl;

  std::vector<int> out(4, -1);

  for (int x = 0; x < width; ++x) {
    for (int y = 0; y < height; ++y) {
      std::cout << "[" << x << ":" << y << "] - ";
      grid.FindAdjacents(x, y, out.begin());
      std::copy(out.begin(), out.end(), os);
      std::fill(out.begin(), out.end(), -1);
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
}

class Node {
  std::pair<int, int> coord_;

 public:
  Node(int x, int y) : coord_(std::make_pair(x, y)) {}
  float getDistance(const Node& node) const {
    return getDistance(node.coord_.first, node.coord_.second);
  };
  float getDistance(const int& x, const int& y) const {
    return std::sqrt((coord_.first + x) * (coord_.first + x) +
                     (coord_.second + y) * (coord_.second + y));
  };

  std::string toString() const {
    return std::to_string(coord_.first) + ":" + std::to_string(coord_.second);
  }

  std::pair<int, int> getCoord() const { return coord_;}
};

int main() {
  Node start(0, 0);
  Node end(4, 4);

  auto comp = [start](const Node& n1, const Node& n2) -> bool {
    return n1.getDistance(start) > n2.getDistance(start);
  };

  auto hashcode = [](const Node& n) -> int {
    auto hash1 = std::hash<int>{}(n.getCoord().first);
    auto hash2 = std::hash<int>{}(n.getCoord().second);
    if (hash1 != hash2) {
      return hash1 ^ hash2;
    }
    return hash1;
  };
  auto equal = [](const Node& n1, const Node& n2) {
    return ((n1.getCoord().first == n2.getCoord().first) &&
            (n1.getCoord().second == n2.getCoord().second));
  };
  std::priority_queue<Node, std::vector<Node>, decltype(comp)> queue(comp);
  std::unordered_set<Node, decltype(hashcode), decltype(equal)> set(32, hashcode, equal);
  set.insert({1, 2});
  set.insert({6, 4});
  set.insert({5, 4});

  std::cout << "it works..." << std::endl;

  for (auto it : set) {
    std::cout << it.toString() << std::endl;
  }
}
