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

/// <summary>
/// O(n^2), stable.
/// Best choice for small array(less then 15) or on almost sorted arrays where
/// the number of inversions is relatively small compared to the size of the
/// array
/// </summary>
/// <param name="begin"> - forward iterator</param>
/// <param name="end"> - forward iterator</param>
void insertionSort(auto begin, auto end) {
  if (begin == end) return;

  auto forward = begin;
  while (std::next(forward) != end) {
    auto backward = forward;
    while (*backward > *std::next(backward)) {
      std::iter_swap(backward, std::next(backward));
      if (backward == begin) break;
      backward = std::prev(backward);
    }
    forward = std::next(forward);
  }
}

/// <summary>
/// The main advantage of heapsort is it's generally much faster than the other
/// comparison based sorts on sufficiently large inputs as a consequence of the
/// running time. However, there are a few undesirable qualities in the
/// algorithm. For one, it is not a stable sort. It also turns out that in
/// practice, this algorithm performs worse than other O(NlogN) sorts as a
/// result of bad cache locality properties.
/// </summary>
/// <param name="begin"></param>
/// <param name="end"></param>
void heapSort(auto begin, auto end) {
  std::make_heap(begin, end);
  // std::sort_heap(begin, end);
  while (begin != end) std::pop_heap(begin, end--);
}