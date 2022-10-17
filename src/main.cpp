#include <algorithm>
#include <bit>
#include <bitset>
#include <format>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

#include "a_star.h"

int main() {
  /*int width = 28, height = 28;

  mysamples::Grid2d<int> grid(width, height);
  std::iota(grid.begin(), grid.end(), 100);

  std::ostream_iterator<int> os(std::cout, " ");
  for (int x = 0; x < width; ++x) {
    std::copy_n(grid.fbegin(0, x), height, os);
    std::cout << std::endl;
  }*/

  std::vector<int> v{1, 2, 3, 4, 4};
  std::vector<int> a{10, 20, 30, 40, 50};
  std::unordered_map<int, int> map;
  
  
  int i = 0;
  
  for (auto it = v.begin(); it != v.end(); ++it) {
    map.insert({*it, a[i++]});
  }
  map.extract(1);
  //map.erase(map.begin());

  for (auto [k, v] : map) {
    std::cout << k << ": " << v << std::endl;
  }
}
