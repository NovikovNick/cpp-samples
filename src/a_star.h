#ifndef EXAMPLEPROJECT_A_STAR_H
#define EXAMPLEPROJECT_A_STAR_H
#include <queue>
#include <unordered_set>

namespace mysamples {

template <typename T>
concept grid = std::is_class_v<T> && requires(T t) {
  t.FindAdjacents();
};

template <typename T>
struct Grid2d {
 private:
  std::vector<T> grid_;
  int width_;
  int height_;

 public:
  Grid2d(const int width, const int height)
      : width_(width), height_(height), grid_(std::vector<T>(width * height)) {}

  auto begin() { return grid_.begin(); }
  auto end() { return grid_.end(); }

  struct iterator {
    using iterator_category = std::contiguous_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

    iterator(pointer ptr) : m_ptr(ptr) {}
    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }

    // Prefix increment
    iterator& operator++() {
      m_ptr++;
      return *this;
    }

    // Postfix increment
    iterator operator++(int) {
      iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    friend bool operator==(const iterator& a, const iterator& b) {
      return a.m_ptr == b.m_ptr;
    };
    friend bool operator!=(const iterator& a, const iterator& b) {
      return a.m_ptr != b.m_ptr;
    };

   private:
    pointer m_ptr;
    int d0_, d1_;
  };

  template <std::output_iterator<int> OutIter>
  void FindAdjacents(int x, int y, OutIter out) {
    if (y + 1 < height_) *(out++) = grid_[width_ * (y + 1) + (x + 0)];
    if (x + 1 < width_) *(out++) = grid_[width_ * (y + 0) + (x + 1)];
    if (y - 1 >= 0) *(out++) = grid_[width_ * (y - 1) + (x + 0)];
    if (x - 1 >= 0) *(out) = grid_[width_ * (y + 0) + (x - 1)];
  }

  iterator fbegin(int x, int y) { return iterator(&grid_[width_ * y + x]); };
};

// NODE should contains pass with costs to prioritised into priority queue
// to output iterator implement tests template <typename NODE>
// exception safety
using NODE = std::pair<int, int>;
using GRID = mysamples::Grid2d<NODE>;
using OutIter = std::vector<NODE>::iterator;

void find(NODE start, NODE goal, GRID grid, OutIter out) {
  //std::priority_queue<NODE> reacheable;
  //std::unordered_set<NODE> explored;
  //std::vector<NODE> adjacents(4);

  //while (!reacheable.empty()) {
  //  auto [x, y] = reacheable.top();
  //  reacheable.pop();
  //  grid.FindAdjacents(x, y, adjacents.begin());
  //  for (auto adjacent : adjacents) {
  //    if (explored.find(adjacent) != explored.end()) {
  //      continue;
  //    }
  //    if (adjacent == goal) {
  //      // calculate path
  //      *out = adjacent;
  //    } else {
  //      reachable.add(adjacent);
  //    }
  //  }
  //  std::fill(adjacents.begin(), adjacents.end(), dummy);
  //  explored.add(cur);
  //}
};

}  // namespace mysamples

#endif  // EXAMPLEPROJECT_A_STAR_H