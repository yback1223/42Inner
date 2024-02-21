#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    std::cout << "numbers:";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\t" << numbers[i];
    }
    std::cout << "\t...";
    for (int i = MAX_VAL - 3; i < MAX_VAL; i++)
    {
        std::cout << "\t" << numbers[i];
    }
    std::cout << std::endl;

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);


        std::cout << "tmp:";
        for (int i = 0; i < 3; i++)
        {
            std::cout << "\t" << tmp[i];
        }
        std::cout << "\t...";
        for (int i = MAX_VAL - 3; i < MAX_VAL; i++)
        {
            std::cout << "\t" << tmp[i];
        }
        std::cout << std::endl;
        std::cout << "test:";
        for (int i = 0; i < 3; i++)
        {
            std::cout << "\t" << test[i];
        }
        std::cout << "\t...";
        for (int i = MAX_VAL - 3; i < MAX_VAL; i++)
        {
            std::cout << "\t" << test[i];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;//
    return 0;
}