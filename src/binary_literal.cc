template <char... Chars>
constexpr int operator"" _binary() {
  int sum = 0;
  for (auto c : {Chars...}) {
    switch (c) {
      case '0':
        sum = sum * 2;
        break;
      case '1':
        sum = sum * 2 + 1;
        break;
      default:
        throw "Unexcpected char";
    }
  }
  return sum;
}