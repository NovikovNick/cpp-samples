
struct A {
  int data;
  A(const int& data) : data(data) {}
};

struct B {
  int data;
  B(const int& data) : data(data) {}
};

template <typename T>
class RefHandler {};

template <>
class RefHandler<A> {
 public:
  static void release() { std::cout << "It was released" << std::endl; }
  static void retain() { std::cout << "It was retained" << std::endl; }
};

template <typename T>
class Wrapper {
 private:
  T data;

 public:
  Wrapper(T data) : data(data) {}
  void relese() { RefHandler<T>::release(); }
};