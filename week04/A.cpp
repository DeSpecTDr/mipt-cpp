#include <iostream>

void print_ptr(const double* ptr) {
  std::cout << ptr << " " << *(long*)ptr << std::endl;
}

int main() {
  double a = 123.456;
  auto* ptr = &a;
  *ptr = 0.1;
  print_ptr(ptr);
  print_ptr(ptr - 3);
  print_ptr(ptr + 5);
  
  return 0;
}
