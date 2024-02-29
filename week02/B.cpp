#include <iostream>

int main() {
  int n = 0;
  int x = 1;
  while (true) {
    std::cin >> x;
    if (x == 0) break;
    n += (1 - x % 2);
  }
  std::cout << n << std::endl;
}
