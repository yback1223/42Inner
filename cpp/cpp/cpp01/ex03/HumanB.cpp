//
// Created by Yong Min Back on 2023/04/26.
//

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
