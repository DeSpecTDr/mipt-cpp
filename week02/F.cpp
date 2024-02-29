#include <iostream>

template <class T>
void print(T s) {
  std::cout << s << std::endl;
}

long fact(long x) {
  if (x == 0) return 1;
  return x * fact(x - 1);
}

int main() {
  int n;
  std::cin >> n;
  print(fact(n));
}
