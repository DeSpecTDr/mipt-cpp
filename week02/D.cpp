#include <iostream>

template <class T>
void print(T s) {
  std::cout << s << std::endl;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  long long int r = 1;
  for (int i = 0; i < m; i++) {
    r *= n;
  }
  print(r);
}
