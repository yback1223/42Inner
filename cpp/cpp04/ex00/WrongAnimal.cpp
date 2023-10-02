/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:22:29 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 15:00:27 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("Wrong Animal") {
	std::cout << "WrongAnimal default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string inputType) : type(inputType) {
	std::cout << "WrongAnimal naming constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	this->type = copy.getType();
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
	if (this != &copy) {
		this->type = copy.getType();
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal default destructor called!" << std::endl;
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