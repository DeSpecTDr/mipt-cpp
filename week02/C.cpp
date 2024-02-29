#include <iostream>

template <class T>
void print(T s) {
  std::cout << s << std::endl;
}

int main() {
  int x;
  std::cin >> x;
  bool flag = false;
  while (x != 1) {
    if (x % 2 != 0) {
      flag = true;
      break;
    }
    x /= 2;
  }
  if (flag) {
    print("NO");
  } else {
    print("YES");
  }
}
