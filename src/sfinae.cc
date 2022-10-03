

class Data final {
 public:
  Data(const int& x) : value_(x) { std::cout << "ctor " << this << std::endl; }

  Data(Data& data) { std::cout << "copy ctor " << this << std::endl; }

  Data(Data&& data) noexcept { std::cout << "move ctor " << this << std::endl; }

 private:
  int value_ = 42;
};

class MyService {
 public:
  template <typename T, typename = std::void_t<decltype(T{}.foo())>>
  T foo(T arg) {
    std::cout << "bar..." << std::endl;
    return arg;
  }
};
