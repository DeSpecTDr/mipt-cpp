#include <array>
// #include <cmath>
#include <cstddef>
#include <cstdint>
// #include <experimental/iterator>
#include <iostream>
// #include <concepts>
#include <ranges>
#include <span>

// #define N 2

// #define MID ((lo + hi + 1) / 2)

constexpr uint64_t sqrt_helper(uint64_t x, uint64_t lo, uint64_t hi) {
  auto mid = (lo + hi + 1) / 2;
  return lo == hi ? lo
                  : ((x / mid < mid) ? sqrt_helper(x, lo, mid - 1)
                                     : sqrt_helper(x, mid, hi));
}

constexpr uint64_t ct_sqrt(uint64_t x) { return sqrt_helper(x, 0, x / 2 + 1); }

template <typename T>
void print(T s) {
  std::cout << s << std::endl;
}

// void println(const auto& seq) {
//   std::copy(std::begin(seq), std::end(seq),
//             std::experimental::make_ostream_joiner(std::cout, " "));
//   std::cout << std::endl;
// }

template <typename T, size_t n>
void read_array(T (&arr)[n]) {
  for (size_t i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
}

// template <typename T, size_t n>
// void print_array(T const (&arr)[n]) {
//   // std::copy(std::begin(arr), std::end(arr),
//             // std::experimental::make_ostream_joiner(std::cout, " "));
//   for (size_t i = 0; i < (n - 1); i++) {
//     std::cout << arr[i] << ' ';
//   }
//   std::cout << arr[n - 1] << std::endl;
// }

template <typename Iter>
void print_array(const Iter begin, const Iter end) {
  auto it = begin;
  if (it != end) {
    std::cout << *it;
    ++it;
    for (; it != end; ++it) {
      std::cout << " " << *it;
    }
  }
  std::cout << std::endl;
}

template <typename T>
void print_array(const T& arr) {
  using std::begin;
  using std::end;
  print_array(begin(arr), end(arr));
}

// template<typename T>
// void better_print(std::span<T const> buf) {
//   buf[0] = 5;
// }

constexpr bool is_square(size_t n) {
  size_t sq = ct_sqrt(n);
  return sq * sq == n;
}

// template<auto n>
// constexpr bool is_square = (((size_t)std::sqrt(n))*((size_t)std::sqrt(n)) ==
// n); constexpr bool is_square = {
//   size_t sq = std::sqrt(n);
//   return sq * sq == n;
// }

template <typename T, size_t n>
void print_matrix(T const (&arr)[n]) {
  const size_t sq = ct_sqrt(n);
  static_assert(sq * sq == n, "n is not a square");

  auto span = std::span{arr};
  for (size_t i = 0; i < sq; i++) {
    auto slice = span.subspan(sq * i, sq);
    print_array(slice);
  }
}

template <typename T, size_t n>
T trace(T (&arr)[n]) {
  const size_t sq = ct_sqrt(n);
  static_assert(sq * sq == n, "n is not a square");

  T sum = 0;
  for (size_t i = 0; i < sq; i++) {
    sum += arr[i * sq + i];
  }
  return sum;
}

const bool A = is_square(4);

// template<size_t n>
// concept IsSquare = requires (n == 5)

int main() {
  int32_t arr[4] = {1, 2, 3, 4};

  // arr[std::slice()]
  // std::array<int32_t, 5> ar = {1, 2, 3, 4, 5};

  // read_array(arr);
  print_array(arr);
  // print_matrix(arr);
  // static_assert(requires(size_t n){false;});
  // static_assert(is_square(4));
  // print(trace(arr));
  // print(1);
  print(A);
  return 0;
}
