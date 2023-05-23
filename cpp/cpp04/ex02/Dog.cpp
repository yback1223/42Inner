/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:45:26 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 15:06:54 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#include "Dog.h"
#include <sstream>

Dog::Dog() : AAnimal("Dog") {
	this->dogBrain = new Brain();
	fillDogBrain();
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog& copy) {
	this->type = copy.getType();
	delete this->dogBrain;
	this->dogBrain = new Brain(*copy.dogBrain);
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	if (this != &copy) {
		this->type = copy.getType();
		delete this->dogBrain;
		this->dogBrain = new Brain(*copy.dogBrain);
	}
	return *this;
}

Dog::~Dog() {
	delete dogBrain;
	dogBrain = NULL;
	std::cout << "Dog default destructor called!" << std::endl;
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