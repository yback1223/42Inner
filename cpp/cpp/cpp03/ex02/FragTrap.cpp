//
// Created by Yong Min Back on 2023/05/01.
//

#include "FragTrap.h"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->setAttackDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);
}

FragTrap::FragTrap(std::string inputName) : ClapTrap(inputName) {
	std::cout << "FragTrap " << this->getName() << " constructor called" << std::endl;
	this->setAttackDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);
}

FragTrap::FragTrap(const FragTrap& copy) {
	std::cout << "FragTrap copy constructor called." << std::endl;
	this->name = copy.getName();
	this->hitPoints = copy.getHitPoints();
	this->energyPoints = copy.getEnergyPoints();
	this->attackDamage = copy.getAttackDamage();
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
	std::cout << "FragTrap operator= " << copy.getName() << " called." << std::endl;
	if (this != &copy) {
		this->name = copy.getName();
		this->hitPoints = copy.getHitPoints();
		this->energyPoints = copy.getEnergyPoints();
		this->attackDamage = copy.getAttackDamage();
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->getName() << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "HIGH FIVE!!!!!" << std::endl;

	this->setHitPoints(this->getHitPoints() - 2);
	this->setEnergyPoints(this->getEnergyPoints() - 2);
}