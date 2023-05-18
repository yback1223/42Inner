//
// Created by Yong Min Back on 2023/05/18.
//

#include "AAnimal.h"

AAnimal::AAnimal() : type("Normal AAnimal") {
	std::cout << this->getType() << " default constructor called!" << std::endl;
}

AAnimal::AAnimal(std::string inputType) : type(inputType) {
	std::cout << this->getType() << " naming constructor called! - name: " << this->getType() << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : type(copy.getType()) {
	std::cout <<  this->getType() << " copy constructor called!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	this->setType(copy.getType());
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << this->getType() << " default destructor called!" << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}

void AAnimal::setType(std::string inputType) {
	this->type = inputType;
}