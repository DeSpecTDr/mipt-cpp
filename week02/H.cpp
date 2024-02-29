#include <iostream>
#include <tuple>

template <class T>
void print(T s) {
  std::cout << s << std::endl;
}

auto gcd(auto a, auto b) {
  while (b > 0) {
    auto tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

template <class T>
std::tuple<T, T> euler(T a, T b) {
  using namespace std;
  T x = 1, y = 0, x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    T q = a1 / b1;
    tie(x, x1) = tuple(x1, x - q * x1);
    tie(y, y1) = tuple(y1, y - q * y1);
    tie(a1, b1) = tuple(b1, a1 - q * b1);
  }
  return {x, y};
}

void solve(int a, int b, int c, int& x, int& y) {
  x = y = 0;
  if (c == 0) return;
  // ax + by = c
  auto g = gcd(a, b);
  if (c % g != 0) return;
  a /= g;
  b /= g;
  c /= g;
  if (a == 0 || b == 0) {
    x = y = c;
    return;
  }
  // solve aX + bY = 1:
  auto [X, Y] = euler(a, b);
  // c (aX + bY) = c => x = cX, y = cY
  x = c * X;
  y = c * Y;
}

int main() {
  int a, b, c, x, y;
  // std::cin >> a >> b >> c;
  a = 2; b = 3, c = 1;
  solve(a, b, c, x, y);
  // auto [x, y] = euler(a, b);
  print(x);
  print(y);
}
