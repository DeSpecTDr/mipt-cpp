#include <cmath>
#include <iostream>

template <class T>
void print(T s) {
  std::cout << s << std::endl;
}

template <class T>
bool is_prime(T x) {
  if (x <= 1) return false;
  if (x == 2 || x == 3) return true;
  if (x % 2 == 0 || x % 3 == 0) return false;
  if ((x - 1) % 6 != 0 && (x + 1) % 6 != 0) return false;
  T sq = std::sqrt(x);
  for (T i = 5; i <= sq; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) return false;
  }
  return true;
}

int main() {
  long n;
  std::cin >> n;
  
  print(is_prime(n) ? "YES" : "NO");
}
