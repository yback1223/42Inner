//
// Created by Yong Min Back on 2023/05/01.
//

#include "Animal.h"

Animal::Animal() : type("Normal Animal") {
	std::cout << this->getType() << " default constructor called!" << std::endl;
}

Animal::Animal(std::string inputType) : type(inputType) {
	std::cout << this->getType() << " naming constructor called! - name: " << this->getType() << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.getType()) {
	std::cout <<  this->getType() << " copy constructor called!" << std::endl;
}

Animal &Animal::operator=(const Animal &copy) {
	this->setType(copy.getType());
	return *this;
}

Animal::~Animal() {
	std::cout << this->getType() << " default destructor called!" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "I am an Animal!!!!" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::setType(std::string inputType) {
	this->type = inputType;
}
