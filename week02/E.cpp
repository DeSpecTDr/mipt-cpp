#include <iostream>

template <class T>
void print(T s) {
  std::cout << s << std::endl;
}

int main() {
  int n;
  std::cin >> n ;
  long x = 1;
  long y = 1;
  for (int i = 0; i < n; i++) {
    auto tmp = x;
    x = y;
    y += tmp;
  }
  print(x);
}
