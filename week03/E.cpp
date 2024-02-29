# include <cstddef>

template <typename T>
void my_swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T, size_t n>
void moveNegativeToEnd(T (&arr)[n]) {
    size_t right = n - 1;
    for (size_t left = 0; left < right; ++left) {
        if (arr[left] >= 0) continue;
        while (left < right && arr[right] < 0) {
            --right;
        }
        if (left > right) break;
        my_swap(arr[left], arr[right]);
        --right;
    }
}

#include "common.cpp"
int main() {
    int32_t arr[7] = {1, -2, 3, -4, 5, -6, 7};
    moveNegativeToEnd(arr);
    print_array(arr);
    return 0;
}