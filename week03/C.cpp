# include <cstddef>

template <typename T>
void my_swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T, size_t n>
void reverseArray(T (&arr)[n]) {
    for (size_t i = 0; i < n / 2; ++i) {
        my_swap(arr[i], arr[n - i - 1]);
    }
}

#include "common.cpp"
int main() {
    int32_t arr[4] = {1, 2, 3, 4};
    reverseArray(arr);
    print_array(arr);
    return 0;
}