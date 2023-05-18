//
// Created by Yong Min Back on 2023/05/01.
//

#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << this->getType() << " default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
	this->type = copy.getType();
	std::cout << this->getType() << " copy constructor called!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	this->type = copy.getType();
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << this->getType() << " default destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat Mung!" << std::endl;
}
