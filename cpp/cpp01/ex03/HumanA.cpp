//
// Created by Yong Min Back on 2023/04/26.
//

#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
