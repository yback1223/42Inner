//
// Created by Yong Min Back on 2023/04/30.
//

#include "ScavTrap.h"

void setStatus(ScavTrap *dumb, int hp, int ep, int attack) {
	dumb->setHitPoints(hp);
	dumb->setEnergyPoints(ep);
	dumb->setAttackDamage(attack);
}

void printStatus(ScavTrap *dumb) {
	std::cout << "=====STAT=====" << std::endl;
	std::cout << "Name: " << dumb->getName() << std::endl;
	std::cout << "HP: " << dumb->getHitPoints() << std::endl;
	std::cout << "EP: " << dumb->getEnergyPoints() << std::endl;
	std::cout << "Damage: " << dumb->getAttackDamage() << std::endl;
	std::cout << "==============" << std::endl;
}

int main() {
	ScavTrap dumb1("dayun");
	ScavTrap dumb2("bcho");

	printStatus(&dumb1);
	printStatus(&dumb2);

	int dayunHP = 100;
	int bchoHP = 150;
	int EP = 10;

	setStatus(&dumb1, dayunHP, EP, 20);
	setStatus(&dumb2, bchoHP, EP, 15);

	int i = 1;

	while (true) {
		std::cout << "===================" << std::endl;
		std::cout << "Round " << i++ << " Fight!" << std::endl;
		dumb1.attack(dumb2.getName());
		dumb2.takeDamage(dumb1.getAttackDamage());
		dumb2.attack(dumb1.getName());
		dumb1.takeDamage(dumb2.getAttackDamage());
//		printStatus(&dumb1);
//		printStatus(&dumb2);
		if (dumb1.getHitPoints() < dayunHP / 2 && i > EP / 2) {
			dumb1.beRepaired(dumb1.getAttackDamage());
		} else if (dumb2.getHitPoints() < bchoHP / 2 && i > EP / 2) {
			dumb2.beRepaired(dumb2.getAttackDamage());
		} else if (i == EP / 3 || i == EP / 4) {
			dumb1.guardGate();
			dumb2.guardGate();
		}
		if (dumb1.getHitPoints() <= 0 || dumb2.getHitPoints() <= 0) {
			break;
		}
		std::cout << "===================" << std::endl;
	}
	if (dumb1.getHitPoints() > dumb2.getHitPoints()) {
		std::cout << dumb1.getName() << " WIN!" << std::endl;
	} else if (dumb1.getHitPoints() < dumb2.getHitPoints()) {
		std::cout << dumb2.getName() << " WIN!" << std::endl;
	} else {
		std::cout << "DRAW!" << std::endl;
	}
	printStatus(&dumb1);
	printStatus(&dumb2);
}

