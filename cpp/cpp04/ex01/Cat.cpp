/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:45:32 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 15:07:40 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#include "Cat.h"
#include <sstream>

Cat::Cat() : Animal("Cat") {
	this->catBrain = new Brain();
	fillCatBrain();
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(const Cat &copy) {
	this->type = copy.getType();
	delete this->catBrain;
	this->catBrain = new Brain(*copy.catBrain);
	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		this->type = copy.getType();
		delete this->catBrain;
		this->catBrain = new Brain(*copy.catBrain);
	}
	return *this;
}

Cat::~Cat() {
	delete catBrain;
	catBrain = NULL;
	std::cout << "Cat default destructor called!" << std::endl;
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