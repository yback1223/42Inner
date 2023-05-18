//
// Created by Yong Min Back on 2023/05/01.
//

#include "Dog.h"

Dog::Dog() : Animal("Dog") {
	std::cout << this->getType() << " default constructor called!" << std::endl;
}

Dog::Dog(const Dog& copy) {
	this->type = copy.getType();
	std::cout << this->getType() << " copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	Animal::operator=(copy);
	return *this;
}

Dog::~Dog() {
	std::cout << this->getType() << " default destructor called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Meong!" << std::endl;
}