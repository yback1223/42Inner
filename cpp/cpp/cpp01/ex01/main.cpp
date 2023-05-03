//
// Created by Yong Min Back on 2023/04/25.
//

#include "Zombie.h"

int main() {

	Zombie zombie = Zombie("stackZombie");
	zombie.announce();

	Zombie *zombies = zombieHorde(9, "hordeZombie");
	for (int i = 0; i < 9; i++) {
		zombies[i].announce();
	}

	delete [] zombies;
//	system("leaks Zombie");
}