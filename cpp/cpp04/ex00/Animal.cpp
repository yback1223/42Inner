/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:17:30 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 14:59:51 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#include "Animal.h"

Animal::Animal() : type("Normal Animal") {
	std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal(std::string inputType) : type(inputType) {
	std::cout << "Animal naming constructor called!(Animal) - name: " << this->getType() << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.getType()) {
	std::cout <<  "Animal copy constructor called!" << std::endl;
}

Animal &Animal::operator=(const Animal &copy) {
	if (this != &copy) {
		this->setType(copy.getType());
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal default destructor called!" << std::endl;
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