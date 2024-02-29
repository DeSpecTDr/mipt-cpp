#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <random>
#include <unordered_map>

template <class T>
void print(T x) {
  std::cout << x << std::endl;
}

template <class T>
T black_box(T x) {
  asm volatile("" : "+r"(x));
  return x;
}

template <class T, size_t N>
auto linear_search(std::span<T, N> s, T needle) {
  size_t n = s.size();
  for (size_t i = 0; i < n; ++i) {
    if (s[i] == needle) {
      return true;
    }
  }
  return false;
}

template <class T, size_t N>
auto binary_search(std::span<T, N> s, T needle) {
  size_t n = s.size();
  size_t l = 0, r = n - 1;
  while (l <= r) {
    auto m = (l + r) / 2;

    if (s[m] == needle) return true;

    if (s[m] < needle)
      l = m + 1;
    else
      r = m - 1;
  }
  return false;
}

template <class T, size_t N>
auto sum_search(std::span<T, N> s, T sum) {
  size_t n = s.size();
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i + 1; j < n; ++j) {
      if (s[i] + s[j] == sum) {
        return true;
      }
    }
  }
  return false;
}

template <class T, size_t N>
auto sum_linear_search(std::span<T, N> s, T sum) {
  size_t n = s.size();
  std::unordered_map<T, size_t> reverse_map;
  for (size_t i = 0; i < n; ++i) {
    reverse_map.insert(std::make_pair(s[i], i));
  }

  for (size_t i = 0; i < n; ++i) {
    auto j = reverse_map.find(sum - s[i]);
    if (j != reverse_map.end()) {
      return true;
    }
  }

  return false;
}

template <class T>
void swap(T& x, T& y) {
  T tmp = x;
  x = y;
  y = tmp;
}

template <class T, size_t N>
auto findA(std::span<T, N> s, T needle) {
  size_t n = s.size();
  for (size_t i = 0; i < n; ++i) {
    if (s[i] == needle) {
      swap(s[0], s[i]);
      return true;
    }
  }
  return false;
}

template <class T, size_t N>
auto findB(std::span<T, N> s, T needle) {
  size_t n = s.size();
  for (size_t i = 0; i < n; ++i) {
    if (s[i] == needle) {
      if (i != 0) {
        swap(s[i - 1], s[i]);
      }
      return true;
    }
  }
  return false;
}

template <class T, size_t N>
auto findC(std::span<T, N> s, std::span<T, N> cache, T needle) {
  size_t n = s.size();
  for (size_t i = 0; i < n; ++i) {
    if (s[i] == needle) {
      cache[i]++;
      if (i != 0 && cache[i - 1] < cache[i]) {
        swap(s[i - 1], s[i]);
        swap(cache[i - 1], cache[i]);
      }
      return true;
    }
  }
  return false;
}

template <class... T>
double bench(T... args) {
  typedef std::chrono::steady_clock clock;
  typedef std::chrono::duration<double, std::milli> duration;

  auto t0 = clock::now();
  for (auto i = 0u; i < 100; ++i) {
    black_box(sum_linear_search(black_box(args)...));
  }
  duration dur = clock::now() - t0;
  return dur.count();
}


template <class... T>
double benchA(T... args) {
  typedef std::chrono::steady_clock clock;
  typedef std::chrono::duration<double, std::milli> duration;

  auto t0 = clock::now();
  for (auto i = 0u; i < 3; ++i) {
    black_box(sum_search(black_box(args)...));
  }
  duration dur = clock::now() - t0;
  return dur.count();
}


double benchC(std::span<int32_t> s, std::span<int32_t> cache, int32_t j) {
  typedef std::chrono::steady_clock clock;
  typedef std::chrono::duration<double, std::milli> duration;

  auto t0 = clock::now();
  for (auto i = 0u; i < 3; ++i) {
    black_box(findC(s, cache, black_box(j)));
  }
  duration dur = clock::now() - t0;
  return dur.count();
}

template <class T, size_t N>
void bench_with(std::span<T, N> s, size_t i) {
  std::mt19937 mt{};
  std::uniform_int_distribution<int32_t> dist(0, (i - 1) * 2);
  std::vector<int32_t> v(i);
  auto cache = std::span(v); // for C benching
  double time = 0;
  for (size_t j = 0; j < 100; ++j) {
    time += benchA(s.subspan(0, i), dist(mt));
    // time += benchC(s.subspan(0, i), cache, dist(mt));
  }
  std::cout << i << "\t" << time << std::endl;
}

int main() {
  const size_t N = 1000000;
  std::array<int32_t, N> arr;
  std::iota(std::begin(arr), std::end(arr), 0);
  auto s = std::span(arr);
  bench_with(s, 100);
  for (size_t i = 10000; i <= N; i += 10000) {
    bench_with(s, i);
  }
  return 0;
}
