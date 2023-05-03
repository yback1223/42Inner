//
// Created by Yong Min Back on 2023/04/26.
//

#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name) {}

HumanA::~HumanA() {}

void HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
