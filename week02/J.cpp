#include <iostream>
#include <string>

template <class T>
void print(T s) {
  std::cout << s << std::endl;
}

int main() {
  int n, base;
  std::cin >> n >> base;
  std::string out{};

  if (n == 0) {
    out = "0";
  }

  while (n > 0) {
    out = std::to_string(n % base) + out;
    n /= base;
  }
  print(out);
}

