//
// Created by Yong Min Back on 2023/05/01.
//

#include "Dog.h"
#include <sstream>

Dog::Dog() : Animal("Dog") {
	this->dogBrain = new Brain();
	fillDogBrain();
	std::cout << this->getType() << " default constructor called!" << std::endl;
}

Dog::Dog(const Dog& copy) {
	this->type = copy.getType();
	this->dogBrain = new Brain(*copy.dogBrain);
	std::cout << this->getType() << " copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	Animal::operator=(copy);
	for (int i = 0; i < 100; i++) {
		this->dogBrain->setIdea(i, copy.dogBrain->getIdea(i));
	}
	return *this;
}

Dog::~Dog() {
	delete dogBrain;
	dogBrain = NULL;
	std::cout << this->getType() << " default destructor called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Meong!" << std::endl;
}

void	Dog::fillDogBrain() {
	for (int i = 0; i < 100; i++) {
		std::stringstream ss;
    	ss << i + 100;
    	std::string strI = ss.str();
		this->dogBrain->setIdea(i, this->getType() + strI);
	}
}

void Dog::getBrainEle(int index) {
	std::cout << dogBrain->getIdea(index) << std::endl;
}

Dog* Dog::clone() const {
	return new Dog(*this);
}