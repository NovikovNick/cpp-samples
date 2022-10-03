
class Data final {
 public:
  Data(const int& x) : value_(x) { std::cout << "ctor " << this << std::endl; }

  Data(Data& data) { std::cout << "copy ctor " << this << std::endl; }

  Data(Data&& data) noexcept { std::cout << "move ctor " << this << std::endl; }

 private:
  int value_ = 42;
};

template <typename T>
T emplace(T&& arg) {
  return std::forward<T>(arg);
}