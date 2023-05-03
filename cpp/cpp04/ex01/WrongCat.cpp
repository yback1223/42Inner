//
// Created by Yong Min Back on 2023/05/01.
//

#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
	std::cout << "WrongCat copy constructor called!" << std::endl;
	this->type = copy.getType();
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	this->type = copy.getType();
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat default destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat Mung!" << std::endl;
}
