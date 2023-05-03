//
// Created by Yong Min Back on 2023/04/25.
//
#include "Zombie.h"

void randomChump(std::string name) {
	Zombie zombie = Zombie(name);
	zombie.announce();
}