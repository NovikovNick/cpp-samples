#ifndef CPP_FEATURES_RANGES_H
#define CPP_FEATURES_RANGES_H

#include <numeric>
#include <random>
#include <ranges>
#include <vector>

#include "../util/log.h"

/// <summary>
/// https://en.cppreference.com/w/cpp/ranges
/// </summary>
namespace ranges {

struct A {
  ~A() { util::debug("desctruct A {}\n", data); }
  int data;
};

template <std::ranges::forward_range Arr>
void addRandom(Arr& arr)
  requires std::integral<std::ranges::range_value_t<Arr>>
{
  std::default_random_engine dre{std::random_device{}()};
  std::uniform_int_distribution random(1, 99);
  for (auto& val : arr) val += random(dre);
}

void sample() {
  util::debug(" === RANGES BEGIN === \n");

  namespace v = std::views;
  namespace r = std::ranges;

  int arr[]{1, 2, 3, 4, 5};

  std::vector<int> nums(10);
  std::vector<std::string> str(10);
  
  addRandom(nums);
  addRandom(arr);
  // addRandom(str);

  // auto toA = [](const int num) { return A{std::to_string(num)}; };

  std::vector<A> dst;
  //  r::copy(nums | v::transform(toA), std::back_inserter(dst));

  for (const auto num : nums) {
    util::debug("{} \n", num);
    // dst.emplace_back(num);
  }

  util::debug(" ===      END     === \n");
}
}  // namespace ranges

#endif  // CPP_FEATURES_RANGES_H