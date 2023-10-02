/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:20:32 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 15:00:16 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#include "Dog.h"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::Dog(const Dog& copy) {
	this->type = copy.getType();
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
	if (this != &copy) {
		this->type = copy.getType();
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog default destructor called!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Meong!" << std::endl;
}