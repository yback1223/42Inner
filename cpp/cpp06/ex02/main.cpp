#include <iostream>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    switch (std::time(0) % 3) {
		case 0:
			return new A;
			break;
		case 1:
			return new B;
			break;
		case 2:
			return new C;
			break;
		default:
			return new Base;
			break;
    }
}

void identify(Base * p) {
    if (dynamic_cast<A *>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p)) std::cout << "C" << std::endl;
    else std::cout << "Base, not A, B, or C" << std::endl;
}

void identify(Base & p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    } catch(const std::exception& e) {}
    
	try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    } catch(const std::exception& e) {}
    
	try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    } catch(const std::exception& e) {}
}

int main()
{
    Base * base = generate();
    identify(base);
    identify(*base);
    delete base;
}