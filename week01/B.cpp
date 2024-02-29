#include <iostream>
#include <cmath>

int main() {
  double a, b, c;
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;
  if (a == 0) {
    if (b != 0) {
      std::cout << -c / b;
    }
  } else {
    auto D = b * b - 4 * a * c;
    if (D == 0) {
      std::cout << -b / (2 * a);
    } else if (D > 0) {
      auto sqD = std::sqrt(D);
      auto x1 = (-b + sqD) / (2 * a);
      auto x2 = (-b - sqD) / (2 * a);
      if (x1 > x2) {
        std::cout << x2 << ' ' << x1;
      } else {
        std::cout << x1 << ' ' << x2;
      }
    }
  }
  std::cout << std::endl;
  
  return 0;
}
