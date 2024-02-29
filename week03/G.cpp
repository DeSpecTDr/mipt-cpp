#include <iostream>
#include <array>
#include <cassert>

# include <cstddef>
# include <span>

template <typename T, size_t n>
size_t find_last_zero(std::span<const T, n> s) {
  size_t l = 0, r = s.size() - 1;
  while (l != r) {
    auto m = (l + r) / 2 + (l + r) % 2;
    if (s[m] == 0) {
      l = m;
    } else {
      r = m - 1;
    }

    // std::cout << m << "\t" << l << "\t" << r << std::endl;
  }
//   auto res = l > r ? r : l;
  auto res = l;
//   assert(s[res] == 0 && s[res + 1] == 1);
  return res;
}

template <typename T, size_t n>
size_t findLastZero(T const (&arr)[n]) {
  return find_last_zero(std::span(arr));
}
// 0 0 0 1 1 1 1

#include "common.cpp"
int main() {
  int32_t arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
  std::array arr2{0, 0, 0, 1, 1, 1};
  print(findLastZero(arr));
  return 0;
}