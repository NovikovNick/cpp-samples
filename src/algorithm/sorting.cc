#include <numeric>

#include "../util/log.h"

/// <summary>
/// O(N^2), not stable
/// </summary>
/// <param name="begin"> - forward iterator</param>
/// <param name="end"> - forward iterator</param>
void selectionSort(auto begin, auto end) {
  while (begin != end) {
    auto min = std::min_element(begin, end);
    if (*min < *begin) std::iter_swap(min, begin);
    begin = std::next(begin);
  }
}

/// <summary>
/// O(N^2), stable
/// </summary>
/// <param name="begin"> - forward iterator</param>
/// <param name="end"> - forward iterator</param>
void bubbleSort(auto begin, auto end) {
  if (begin == end) return;

  while (std::next(begin) != end) {
    auto fst = begin;
    auto snd = std::next(fst);
    while (snd != end) {
      if (*fst > *snd) std::iter_swap(fst, snd);
      fst = snd;
      snd = std::next(snd);
    }
    end = std::prev(end);
  }
}