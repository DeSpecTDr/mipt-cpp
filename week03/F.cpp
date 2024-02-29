# include <cstddef>

template <typename T>
void my_swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T, size_t n>
void mergeArrays(T (&lhs)[n], T (&rhs)[n], T (&res)[2 * n]) {
    for (size_t i = 0; i < n; ++i) {
        res[i] = lhs[i];
    }
    for (size_t i = 0; i < n; ++i) {
        res[i + n] = rhs[i];
    }
}

#include "common.cpp"
int main() {
    int32_t arr[7] = {1, -2, 3, -4, 5, -6, 7};
    int32_t arr2[14] = {0};
    mergeArrays(arr, arr, arr2);
    print_array(arr2);
    return 0;
}