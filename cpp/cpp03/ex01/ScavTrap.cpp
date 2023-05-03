//
// Created by Yong Min Back on 2023/04/30.
//

#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
	this->gateMode = 0;
}

ScavTrap::ScavTrap(std::string InputName) : ClapTrap(InputName) {
	std::cout << "ScavTrap " << this->getName() << " constructor called" << std::endl;
	this->setAttackDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
	this->gateMode = 0;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
	std::cout << "ScavTrap copy constructor called." << std::endl;
	this->name = copy.getName();
	this->hitPoints = copy.getHitPoints();
	this->energyPoints = copy.getEnergyPoints();
	this->attackDamage = copy.getAttackDamage();
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
	std::cout << "ScavTrap operator= " << copy.getName() << " called." << std::endl;
	if (this != &copy) {
		this->name = copy.getName();
		this->hitPoints = copy.getHitPoints();
		this->energyPoints = copy.getEnergyPoints();
		this->attackDamage = copy.getAttackDamage();
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->getName() << " destructor called" << std::endl;
}

void ScavTrap::guardGate() {
	if (this->gateMode) {
		std::cout << "ScavTrap " << this->getName() << " Gate keeper mode OFF" << std::endl;
		this->gateMode = false;
	} else {
		std::cout << "ScavTrap " << this->getName() << " Gate keeper mode ON" << std::endl;
		this->gateMode = true;
		this->setEnergyPoints(this->getEnergyPoints() + 2);
	}
}

void ScavTrap::attack(const std::string &target) {
	if (this->getEnergyPoints() > 0) {
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << "ScavTrap <<" << this->getName() << ">> attacks " << target << " causing " << this->getAttackDamage()
		          << " points of damage! " << std::endl;
	} else {
		std::cout << "ScavTrap <<" << this->getName() << ">> have no energy point to attack!" << std::endl;
	}
}