#include "iter.hpp"
#include <iostream>

template<typename T>
void func(T& e) {
    std::cout << e << std::endl;
}

template<typename T, std::size_t N>
std::size_t arrSize(T(&)[N]) {
    return N;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
    // double arr[] = {.0, .1, .2, .3, .4, .5, .6, .7, .8, .9, };

    iter(arr, arrSize(arr), &func);;
}