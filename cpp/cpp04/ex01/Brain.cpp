/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:23:31 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 14:24:04 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#include "Brain.h"

Brain::Brain() {
	std::cout << "Brain default constructor called!" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain default destructor called!" << std::endl;
}

Brain::Brain(const Brain &copy) {
	std::cout << "Brain copy constructor called!" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->setIdea(i, copy.getIdea(i));
	}
}

Brain &Brain::operator=(const Brain &copy) {
	if (this != &copy) {
		for (int i = 0; i < 100; i++) {
			this->setIdea(i, copy.getIdea(i));
		}
	}
	return *this;
}

void Brain::setIdea(int index, std::string type) {
	this->ideas[index] = type;
}

std::string Brain::getIdea(int index) const {
	return this->ideas[index];
}
