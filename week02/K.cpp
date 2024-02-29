#include <iostream>

template <class T>
void print(T s) {
  std::cout << s << std::endl;
}

int main() {
  long a, k, m;
  std::cin >> a >> k >> m;

  long r = 1;
  while (k--) {
    r = (r * a) % m;
  }

  print(r);
}

