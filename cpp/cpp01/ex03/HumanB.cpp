/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:30:44 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:30:45 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB(const std::string name) : name(name), weapon(NULL){
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() const {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
