#include <iostream>

int main() {
  unsigned int x;
  std::cin >> x;
  if (x % 4 == 0 && (x % 100 != 0 || x % 400 == 0)) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  return 0;
}
