//
// Created by Yong Min Back on 2023/04/25.
//
#include "Zombie.h"

Zombie *newZombie(std::string name) {
	return new Zombie(name);
}