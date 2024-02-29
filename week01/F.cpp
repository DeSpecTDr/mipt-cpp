#include <cmath>
#include <iostream>
#include <string>

int main() {
  int n;
  std::cin >> n;
  auto s = std::to_string(n);
  int flag = 1;
  for (int i = 0; i < (s.length() + 1) / 2; i++) {
    if (s[i] != s[s.length() - i - 1]) {
      flag = 0;
    }
  }
  std::cout << flag << std::endl;
  return 0;
}
