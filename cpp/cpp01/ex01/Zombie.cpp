/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:29:56 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:29:58 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << getName() << " head shot!" << std::endl;
}

void Zombie::announce() {
	std::cout << getName() << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName() {
	return name;
}

void Zombie::setName(std::string input) {
	this->name = input;
}