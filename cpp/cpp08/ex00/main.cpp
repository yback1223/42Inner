#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main( void ) {
    int arr[] =  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vec(arr, arr + 10);
    std::deque<int> deq(arr, arr + 10);
    std::list<int> list(arr, arr + 10);

    searchAndPrint(vec, 1);
    searchAndPrint(vec, 11);
    searchAndPrint(deq, 1);
    searchAndPrint(deq, 11);
    searchAndPrint(list, 1);
    searchAndPrint(list, 11);
    
    return 0;
}
