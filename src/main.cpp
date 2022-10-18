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

template <typename T>
concept GraphNode = std::is_class_v<T> && std::is_lvalue_reference_v<T>;

template <GraphNode T>
void foo(T node) {
  std::cout << " -- " << std::endl;
}
struct A {
  int x;
  A(int x) : x(x) {}
};

struct pair {
  int key;
  mutable int val;
};

int main() {
  /*int width = 28, height = 28;

  mysamples::Grid2d<int> grid(width, height);
  std::iota(grid.begin(), grid.end(), 100);

  std::ostream_iterator<int> os(std::cout, " ");
  for (int x = 0; x < width; ++x) {
    std::copy_n(grid.fbegin(0, x), height, os);
    std::cout << std::endl;
  }*/

  
}
