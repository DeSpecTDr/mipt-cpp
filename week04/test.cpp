#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <span>
#include <vector>
#include <ranges>

void print(const auto& val) {
  std::cout << val << std::endl;
}

void print_array(const auto& cont) {
  auto s = std::span(cont);
  auto size = s.size();
  if (size > 0) {
    std::cout << s[0];
    for (size_t i = 1; i < size; ++i) {
      std::cout << " " << s[i];
    }
  }
  std::cout << std::endl;
}

void print2(const std::ranges::input_range auto& val) {
  // std::ranges::copy(val, std::ostream_iterator(std::cout, " "));
  // val | ranges::ostream_iterator(std::cout, " ")
  // std::ranges::ostream_iterator
}

void print_matrix() {
  
}

void test_print() {
  int32_t arr[] = {1};
  std::array arr2{int32_t(1), 2, 3, 4, 5};
  std::vector vec{int32_t(1), 2, 3};

  std::array<int32_t, 0> zero{};

  print_array(arr);
  print_array(arr2);
  print_array(zero);
  print_array(vec);

  print(1);
  print("123");  
}

int main() {
  test_print();
}
