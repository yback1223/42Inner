/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:32:26 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:32:27 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon(std::string weaponType) : type(weaponType) {}

Weapon::Weapon() {}

Weapon::~Weapon() {}

const std::string &Weapon::getType() const {
	return this->type;
}

void Weapon::setType(std::string newType) {
	this->type = newType;
}