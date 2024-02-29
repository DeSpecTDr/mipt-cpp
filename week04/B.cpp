#include <cstddef>
#include <cstdint>
#include <iostream>

int main() {
  // uint8_t a = 123;
  // auto* ptr = &a;
  
  auto *arr = new uint8_t[10];
  for (uint8_t i = 0; i < 10; ++i) {
    arr[i] = i;
  }

  
  for (uint8_t i = 0; i < 10; ++i) {
    std::cout << &arr[i] << std::endl;
  }
  
  return 0;
}

