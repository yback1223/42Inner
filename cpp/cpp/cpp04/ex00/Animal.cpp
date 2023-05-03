//
// Created by Yong Min Back on 2023/05/01.
//

#include "Animal.h"

Animal::Animal() {
	this->setType("Animal");
	std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal(std::string inputType) {
	this->setType(inputType);
	std::cout << "Animal naming constructor called!\n- name: " << this->getType() << std::endl;
}

Animal::Animal(const Animal &animal) : type(animal.getType()) {
	std::cout << "Animal copy constructor called!" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
	if (this != &animal) {
		this->type = animal.type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal default destructor called!" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal Sound~!!!!" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::setType(std::string inputType) {
	this->type = inputType;
}