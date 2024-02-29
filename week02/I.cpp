#include <iostream>

template <class T>
void print(T s) {
  std::cout << s << std::endl;
}

int main() {
  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    int p = 0;
    while (a > 1) {
      a /= 2;
      p++;
    }
    print(p);
  }
}
