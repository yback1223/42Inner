//
// Created by Yong Min Back on 2023/05/01.
//

#include "Cat.h"
#include <sstream>

Cat::Cat() : AAnimal("Cat") {
	this->catBrain = new Brain();
	fillCatBrain();
	std::cout << this->getType() << " default constructor called!" << std::endl;
}

Cat::Cat(const Cat &copy) {
	this->type = copy.getType();
	this->catBrain = new Brain(*copy.catBrain);
	std::cout << this->getType() << " copy constructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
	AAnimal::operator=(copy);
	for (int i = 0; i < 100; i++) {
		this->catBrain->setIdea(i, copy.catBrain->getIdea(i));
	}
	return *this;
}

Cat::~Cat() {
	delete catBrain;
	catBrain = NULL;
	std::cout << this->getType() << " default destructor called!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Yaong!" << std::endl;
}

void	Cat::fillCatBrain() {
	for (int i = 0; i < 100; i++) {
		std::stringstream ss;
    	ss << i;
    	std::string strI = ss.str();
		this->catBrain->setIdea(i, this->getType() + strI);
	}
}

void Cat::getBrainEle(int index) {
	std::cout << catBrain->getIdea(index) << std::endl;
}

Cat* Cat::clone() const {
	return new Cat(*this);
}