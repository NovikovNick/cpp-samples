#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

void mapSample() {
  std::unordered_map<int, int> map(24);
  map[1] = 2;
  map[34] = 2;

  for (int i = 0; i < 10; ++i) {
    map[i] = i * 10;
  }

  for (auto it : map) {
    std::cout << it.first << ": " << it.second << std::endl;
  }

  std::cout << " ---------------  " << std::endl;

  for (int i = 0; i < map.bucket_count(); ++i) {
    std::for_each(map.cbegin(i), map.cend(i), [i](auto it) {
      auto [key, val] = it;
      std::cout << i << ". " << key << ":" << val << std::endl;
    });
  }

  ([]() {})();
}

void samples() {
  std::ostream_iterator<int> os(std::cout, " ");
  std::vector<int> a(10);
  std::iota(a.begin(), a.end(), 1);

  std::copy(a.begin(), a.end(), os);
  std::cout << std::endl;

  std::transform(a.begin(), a.end(), a.begin(), [](auto&& i) { return -i; });
  std::copy(a.begin(), a.end(), os);
  std::cout << std::endl;

  auto is_odd = [](auto i) { return i % 2 != 0; };
  a.erase(std::remove_if(a.begin(), a.end(), is_odd), a.end());
  std::copy(a.begin(), a.end(), os);
  std::cout << std::endl;
}


void rotateSample() {
    
  std::cout << "std::rotate(ForwardIT fst, ForwardIT mid, ForwardIT lst)" << std::endl;

  std::ostream_iterator<int> os(std::cout, " ");
  std::vector<long> a(10);
  std::iota(a.begin(), a.end(), 1);

  std::copy(a.begin(), a.end(), os);
  std::cout << std::endl;

  std::rotate(a.begin(), std::find(a.begin(), a.end(), 5), a.end());
  std::copy(a.begin(), a.end(), os);
  std::cout << std::endl;

  std::copy(a.begin(), a.end(), os);
  std::cout << std::endl;
}