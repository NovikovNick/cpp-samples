#include <queue>

#include "../util/log.h"


/*

  std::vector<int> output(3);
  std::vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  emplaceTopMinElements(output, input);
  for (const auto& it : output) {
    util::debug("{} ", it);
  }
  util::debug("\n");

*/


void topMaxElements(std::vector<int>& output, const int k,
                    std::vector<int>& input) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  for (const auto& it : input) {
    min_heap.push(it);
    if (min_heap.size() > k) min_heap.pop();
  }

  while (!min_heap.empty()) {
    output.push_back(min_heap.top());
    min_heap.pop();
  }
}

void topMinElements(std::vector<int>& output, const int k,
                    std::vector<int>& input) {
  std::priority_queue<int> max_heap;
  for (const auto& it : input) {
    max_heap.push(it);
    if (max_heap.size() > k) max_heap.pop();
  }

  while (!max_heap.empty()) {
    output.push_back(max_heap.top());
    max_heap.pop();
  }
}

void emplaceTopMaxElements(std::vector<int>& output, std::vector<int>& input) {
  // if input.size() > output.size() and output is empty
  std::fill(output.begin(), output.end(), INT_MIN);
  auto comparator = std::greater<int>{};

  for (const auto& it : input) {
    output.push_back(it);
    std::push_heap(output.begin(), output.end(), comparator);

    std::pop_heap(output.begin(), output.end(), comparator);
    output.pop_back();
  }
}

void emplaceTopMinElements(std::vector<int>& output, std::vector<int>& input) {
  // if input.size() > output.size() and output is empty
  std::fill(output.begin(), output.end(), INT_MAX);
  auto comparator = std::less<int>{};

  for (const auto& it : input) {
    output.push_back(it);
    std::push_heap(output.begin(), output.end(), comparator);

    std::pop_heap(output.begin(), output.end(), comparator);
    output.pop_back();
  }
}