

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

template <typename T, size_t size>
class fixed_vector {
 public:
  using iterator = T*;
  using const_iterator = const T*;

  fixed_vector(){};

  /*template <typename U,
            size_t osize,
            std::enable_if_t<std::is_same<T, U>::value, bool> = true>*/
  template <typename U, size_t osize>
    requires std::same_as<T, U>
  fixed_vector(const fixed_vector<U, osize>& other) {
    *this = other;
  }

  /*template <typename U,
            size_t osize,
            std::enable_if_t<std::is_same<T, U>::value, bool> = true>*/
  template <typename U, size_t osize>
    requires std::same_as<T, U>
  fixed_vector<T, size>& operator=(const fixed_vector<U, osize>& other) {
    std::copy(other.begin(),                                  //
              other.begin() + std::min<size_t>(osize, size),  //
              begin());
    return *this;
  }

  iterator begin() { return v_; }
  iterator end() { return v_ + size; }
  const_iterator begin() const { return v_; }
  const_iterator end() const { return v_ + size; }

 private:
  T v_[size];
};