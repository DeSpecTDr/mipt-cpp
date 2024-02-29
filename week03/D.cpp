# include <cstddef>

template<typename T, size_t n>
void shiftArrayRight(T (&arr)[n]) {
    T tmp = arr[n - 1];
    for (size_t i = n - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = tmp;
}

#include "common.cpp"
int main() {
    int32_t arr[7] = {1, 2, 3, 4, 5, 6, 7};
    shiftArrayRight(arr);
    print_array(arr);
    return 0;
}