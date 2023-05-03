//
// Created by Yong Min Back on 2023/05/01.
//

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called!" << std::endl;
	this->setType("WrongAnimal");
}

WrongAnimal::WrongAnimal(std::string inputType) {
	std::cout << "WrongAnimal naming constructor called!" << std::endl;
	this->setType(inputType);
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
	this->type = copy.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	this->type = copy.getType();
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal default destructor called!" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wrong Animal Sound!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::setType(std::string inputType) {
	this->type = inputType;
}