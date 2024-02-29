#include <iostream>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  int out = 1;
  for (int i = 2; i <= n; i++) {
    out *= i;
  }
  std::cout << out << std::endl;
  return 0;
}
