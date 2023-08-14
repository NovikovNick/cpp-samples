#ifndef CPP_FEATURES_FOLD_H
#define CPP_FEATURES_FOLD_H
#include <vector>
#include "../util/log.h"

/// <summary>
/// https://en.cppreference.com/w/cpp/language/fold
/// </summary>
namespace fold {

void log(int x) { util::debug("{}\n", x); }

template <typename... Args>
void fold(Args... args) {
  // unary right fold:  (args + ...)        -> (1 + (2 + (3 + 4)))
  // unary left fold:   (... + args)        -> (((1 + 2) + 3) + 4)
  // binary right fold: (args + ... + init) -> (1 + (2 + (3 + (4 + 100))))
  // binary left fold:  (init + ... + args) -> ((((100 + 1) + 2) + 3) + 4)

  // (std::cout << ... << args); // ((((std::cout << 1) << 2) << 3) << 4);
  (log(args), ...);  // (log(1), (log(2), (log(3), (log(4)))))
}

template <typename... Args>
void fillArray(std::vector<int>& arr, Args... args) {
  (..., arr.push_back(args));
  (arr.push_back(args), ...);
}

void printArray(const std::vector<int>& arr) {
  for (const auto num : arr) util::debug("{} ", num);
  util::debug("\n");
}

void sample() {
  // fold(1, 2, 3, 4);

  std::vector<int> arr;
  fillArray(arr, 1, 2, 3, 4);
  printArray(arr);
}

}  // namespace fold

#endif  // CPP_FEATURES_FOLD_H