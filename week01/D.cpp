#include <iostream>

int gcd(int a, int b) {
  while (b > 0) {
    auto tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
