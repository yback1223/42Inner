//
// Created by Yong Min Back on 2023/05/01.
//

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("Wrong Animal") {
	std::cout << this->getType() << " default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string inputType) : type(inputType) {
	std::cout << this->getType() << " naming constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	this->type = copy.getType();
	std::cout << this->getType() << " copy constructor called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	this->type = copy.getType();
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << this->getType() << " default destructor called!" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "I am a Wrong Animal!!!!!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::setType(std::string inputType) {
	this->type = inputType;
}