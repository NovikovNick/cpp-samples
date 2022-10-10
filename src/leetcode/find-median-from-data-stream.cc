#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#ifndef LEETCODE_FIND_MEDIAN_FROM_DATA_STREAM_H
#define LEETCODE_FIND_MEDIAN_FROM_DATA_STREAM_H

namespace leetcode {

using namespace std;

class MedianFinder {
 private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap_;
  std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap_;

  void add(int num) {
    if (maxHeap_.size() >= minHeap_.size()) {
      minHeap_.push(num);
    } else {
      maxHeap_.push(num);
    }
  }

  void rebalance() {
    if (minHeap_.empty() || maxHeap_.empty()) {
      return;
    }

    int max, min;
    while ((max = maxHeap_.top()) > (min = minHeap_.top())) {
      maxHeap_.pop();
      minHeap_.pop();
      minHeap_.push(max);
      maxHeap_.push(min);
    }
  }

 public:
  MedianFinder() {}

  void addNum(int num) {
    add(num);
    rebalance();
  }

  double findMedian() {
    auto minHeapSize = minHeap_.size();
    auto maxHeapSize = maxHeap_.size();
    if (minHeapSize == maxHeapSize) {
      return (maxHeap_.top() + minHeap_.top()) / 2.0;
    } else {
      return minHeapSize > maxHeapSize ? minHeap_.top() : maxHeap_.top();
    }
  }
};
}  // namespace leetcode
#endif  // LEETCODE_FIND_MEDIAN_FROM_DATA_STREAM_H
