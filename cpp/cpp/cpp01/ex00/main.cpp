//
// Created by Yong Min Back on 2023/04/25.
//

#include "Zombie.h"

int main() {
	Zombie stackZombie = Zombie("stackZombie");
	Zombie *heapZombie = newZombie("heapZombie");

	stackZombie.announce();
	heapZombie->announce();

	randomChump("randomZombie");

	delete heapZombie;
	system("leaks Zombie");
}