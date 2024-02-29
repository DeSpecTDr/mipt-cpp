#include <iostream>

#define ll long long

template <class T>
void print(T s) {
  std::cout << s << std::endl;
}

int main() {
  ll a, k, m;
  std::cin >> a >> k >> m;

  ll r = 1;
  while (k--) {
    auto i = r;
    r = 1;
    while (i--) {
      r = (r * a) % m;
    }
  }

  print(r);
}
