#include <array>
// #include <cmath>
#include <cstddef>
#include <cstdint>
// #include <experimental/iterator>
#include <iostream>
// #include <concepts>
#include <ranges>
#include <span>

template <typename T>
void print(T s) {
  std::cout << s << std::endl;
}

template <typename Iter>
void print_array(const Iter begin, const Iter end) {
  auto it = begin;
  std::cout << *it;
  ++it;
  for (; it != end; ++it) {
    std::cout << " " << *it;
  }
  std::cout << std::endl;
}

template <typename T>
void print_array(const T& arr) {
  using std::cbegin;
  using std::cend;
  print_array(cbegin(arr), cend(arr));
}
