/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:19:15 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 15:00:07 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#include "Cat.h"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called!" << std::endl;
}

Cat::Cat(const Cat &copy) {
	this->type = copy.getType();

	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat &Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		this->type = copy.getType();
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat default destructor called!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Yaong!" << std::endl;
}

