//
// Created by Yong Min Back on 2023/05/01.
//

#include "Cat.h"

Cat::Cat() : Animal("Cat") {
	std::cout << this->getType() << " default constructor called!" << std::endl;
}

Cat::Cat(const Cat &copy) {
	this->type = copy.getType();
	std::cout << this->getType() << " copy constructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
	Animal::operator=(copy);
	return *this;
}

Cat::~Cat() {
	std::cout << this->getType() << " default destructor called!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Yaong!" << std::endl;
}

