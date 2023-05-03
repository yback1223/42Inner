//
// Created by Yong Min Back on 2023/04/25.
//

#include "Zombie.h"

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
	return this->name;
}
