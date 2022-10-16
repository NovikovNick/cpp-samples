#ifndef EXAMPLEPROJECT_A_STAR_H
#define EXAMPLEPROJECT_A_STAR_H

namespace mysamples {

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

  struct Iterator {
    using iterator_category = std::contiguous_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

    Iterator(pointer ptr) : m_ptr(ptr) {}
    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }

    // Prefix increment
    Iterator& operator++() {
      m_ptr++;
      return *this;
    }

    // Postfix increment
    Iterator operator++(int) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    friend bool operator==(const Iterator& a, const Iterator& b) {
      return a.m_ptr == b.m_ptr;
    };
    friend bool operator!=(const Iterator& a, const Iterator& b) {
      return a.m_ptr != b.m_ptr;
    };

   private:
    pointer m_ptr;
    int d0_, d1_;
  };

  Iterator fbegin(int x, int y) { return Iterator(&grid_[width_ * y + x]); };
};

template <typename NODE>
void find(NODE start, NODE goal, int widght, int height) {
  //std::vector<NOTE> reacheable(widght * height, start.FindAdjacents());
  //std::vector<NOTE> explored(widght * height, start);

  //while (reachable.isNotEmpty()) {
  //  auto cur = reachable.popMostPrioritiesNode();
  //  for (auto adjacent : cur.FindAdjacents()) {
  //    if (contains(adjacent, explored)) {
  //      continue;
  //    }

  //    if (adjacent == goal) {
  //      // calculate path
  //    } else {
  //      reachable.add(adjacent);
  //    }
  //  }
  //  explored.add(cur);
  //}
};

}  // namespace mysamples

#endif  // EXAMPLEPROJECT_A_STAR_H