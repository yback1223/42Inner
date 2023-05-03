//
// Created by Yong Min Back on 2023/05/01.
//

#include "Dog.h"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog& copy) {
	std::cout << "Dog copy constructor called!" << std::endl;
	this->type = copy.getType();
}

Dog& Dog::operator=(const Dog& copy) {
	this->type = copy.getType();
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Mung!" << std::endl;
}