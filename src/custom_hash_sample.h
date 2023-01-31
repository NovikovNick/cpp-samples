namespace sample {

struct Coord {
  int x, y;
  void move(const char dir) {
    switch (dir) {
      case 'N':
        --y;
        break;
      case 'S':
        ++y;
        break;
      case 'W':
        ++x;
        break;
      case 'E':
        --x;
        break;
    }
  }
};

bool operator==(const Coord& lhs, const Coord& rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

namespace std {
template <>
struct hash<Coord> {
  std::size_t operator()(const Coord& coord) const {
    auto h1 = std::hash<int>{}(coord.x);
    auto h2 = std::hash<int>{}(coord.y);
    return h1 == h2 ? h1 : h1 ^ h2;
  }
};
}  // namespace std

class Solution {
 public:
  bool isPathCrossing(string path) {
    int n = path.size();
    std::unordered_set<Coord> hashset;
    Coord pos{0, 0};
    hashset.insert(pos);
    for (int i = 0; i < n; ++i) {
      pos.move(path[i]);
      if (hashset.insert(pos).second != true) return true;
    }
    return false;
  }
};
}  // namespace sample
