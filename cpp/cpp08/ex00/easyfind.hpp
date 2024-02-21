#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
void searchAndPrint(T &container, int target) {
    if (std::find(container.begin(), container.end(), target) != container.end()) std::cout << target << " is found" << std::endl;
    else std::cout << target << " is not found" << std::endl;
}

#endif
