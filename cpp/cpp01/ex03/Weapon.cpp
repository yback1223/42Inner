//
// Created by Yong Min Back on 2023/04/26.
//

#include "Weapon.h"

Weapon::Weapon(std::string weaponType) : type(weaponType) {}

Weapon::~Weapon() {}

const std::string Weapon::getType() const {
	return type;
}

void Weapon::setType(std::string newType) {
	this->type = newType;
}