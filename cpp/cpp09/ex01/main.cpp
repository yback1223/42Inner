#include <iostream>
#include "Rpn.hpp"

int main(int argc, char * argv[]) {
    if (argc != 2 || argv[1] == NULL) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    try
    {
        Rpn rpn(argv[1]);
        std::cout << rpn.calc() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error" << std::endl;;
    }
    
}