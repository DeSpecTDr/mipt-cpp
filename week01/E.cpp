#include <cmath>
#include <iostream>

int gcd(int a, int b) {
  while (b > 0) {
    auto tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

long lcm(int a, int b) {
  return std::abs(a / gcd(a, b) * (long)b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
