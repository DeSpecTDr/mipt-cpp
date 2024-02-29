#include <iostream>

# include <cstddef>

template<typename T, size_t n, size_t m>
void printTransposed(T (&arr)[n][m]) {
    for (size_t i = 0; i < m; ++i) {
        std::cout << arr[0][i];
        for (size_t j = 1; j < n; ++j) {
            std::cout << " " << arr[j][i];
        }
        std::cout << std::endl;
    }
}

#include "common.cpp"
int main() {
    int32_t arr[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    // print(findLastZero(arr));
    printTransposed(arr);
    return 0;
}