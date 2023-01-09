#include <chrono>
#include <future>
#include <thread>
#include <vector>

#include "../util/log.h"

namespace sample_concur {

void print(const std::list<int>& arr) {
  for (const auto& it : arr) util::debug("{} ", it);
  util::debug("\n");
}

std::list<int> parallel_quick_sort(std::list<int> input) {
  if (input.empty()) return input;

  std::list<int> result;
  result.splice(result.begin(), input, input.begin());
  const int& pivot = *result.begin();

  auto div_point = std::partition(input.begin(), input.end(),
                                  [&](const auto& t) { return t < pivot; });

  std::list<int> lower_part;
  lower_part.splice(lower_part.end(), input, input.begin(), div_point);

  auto new_lower(
      std::async(&parallel_quick_sort, std::move(lower_part)));  // 1.
  auto new_higher(parallel_quick_sort(std::move(input)));        // 2.

  result.splice(result.end(), new_higher);         // 3.
  result.splice(result.begin(), new_lower.get());  // 4.
  return result;
}

std::list<int> sequential_quick_sort(std::list<int> input) {
  if (input.empty()) return input;

  std::list<int> result;
  result.splice(result.begin(), input, input.begin());  // 1.
  const int& pivot = *result.begin();                   // 2.

  auto div_point =
      std::partition(input.begin(), input.end(),
                     [&](const auto& t) { return t < pivot; });  // 3.

  std::list<int> lower_part;
  lower_part.splice(lower_part.end(), input, input.begin(), div_point);  // 4.

  auto new_lower(sequential_quick_sort(std::move(lower_part)));  // 5.
  auto new_higher(sequential_quick_sort(std::move(input)));      // 6.

  result.splice(result.end(), new_higher);   // 7.
  result.splice(result.begin(), new_lower);  // 8.
  return result;
}

void quick_sort_sample() {
  std::list<int> nums{6, 2, 7, 8, 3, 1, 4, 5, 9};

  nums = sequential_quick_sort(nums);
  // num = parallel_quick_sort(num);
  print(nums);

  /*std::list<int> res;
  res.splice(res.end(), num, num.begin());
  print(num);
  print(res);*/
}

}  // namespace sample_concur
