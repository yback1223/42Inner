/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:53 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 14:54:09 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/18.
//

#include "AAnimal.h"

AAnimal::AAnimal() : type("Normal AAnimal") {
	std::cout << "AAnimal default constructor called!" << std::endl;
}

AAnimal::AAnimal(std::string inputType) : type(inputType) {
	std::cout << "AAnimal naming constructor called! - name: " << this->getType() << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : type(copy.getType()) {
	std::cout << "AAnimal copy constructor called!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	if (this != &copy) {
		this->setType(copy.getType());
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal default destructor called!" << std::endl;
}

std::string AAnimal::getType() const {
	return this->type;
}

void AAnimal::setType(std::string inputType) {
	this->type = inputType;
}