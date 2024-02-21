#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void iter(T arr[], int len, void (*func)(T&)) {
    if (arr == nullptr) return;
    try {
        for (int i = 0; i < len; i++) {
            func(arr[i]);
        }
    } catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

#endif
