/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:22:24 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 14:59:30 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#include "WrongCat.h"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
	this->type = copy.getType();
	std::cout << "WrongCat copy constructor called!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	if (this != &copy) {
		this->type = copy.getType();
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat default destructor called" << std::endl;
}
