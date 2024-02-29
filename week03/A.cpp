#define N 5

# include <experimental/iterator>
# include <iostream>
# include <iterator>

void printArray(int (&arr)[N]) {
  std::copy(std::begin(arr), std::end(arr),
            std::experimental::make_ostream_joiner(std::cout, " "));
  std::cout << std::endl;
}

template <class T>
void print(T s) {
  std::cout << s << std::endl;
}

void readArray(int (&arr)[N]) {
  for (int i = 0; i < N; i++) {
    int x;
    std::cin >> x;
    arr[i] = x;
  }
}

int main() {
  int arr[N] = {0};
  readArray(arr);
  printArray(arr);
  print(1);
  return 0;
}
