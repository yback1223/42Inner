//
// Created by Yong Min Back on 2023/05/01.
//

#include "Cat.h"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(const Cat &copy) {
	std::cout << "Cat copy constructor called!" << std::endl;
	this->type = copy.getType();
}

Cat &Cat::operator=(const Cat &copy) {
	this->type = copy.getType();
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat default destructor called!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Yaong!" << std::endl;
}

