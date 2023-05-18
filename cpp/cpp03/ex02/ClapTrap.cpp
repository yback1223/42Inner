/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:58:13 by yback             #+#    #+#             */
/*   Updated: 2023/05/18 10:29:42 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/04/30.
//

#include "ClapTrap.h"

ClapTrap::ClapTrap() : name("defaultName"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Call ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Call ClapTrap naming constructor\n- name: " << this->getName() << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << "ClapTrap copy constructor called!" << std::endl;
	this->setName(copy.getName());
	this->setHitPoints(copy.getHitPoints());
	this->setEnergyPoints(copy.getEnergyPoints());
	this->setAttackDamage(copy.getAttackDamage());
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
	std::cout << "ClapTrap copy assignment operator called!" << std::endl;
	this->setName(copy.getName());
	this->setHitPoints(copy.getHitPoints());
	this->setEnergyPoints(copy.getEnergyPoints());
	this->setAttackDamage(copy.getAttackDamage());
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Call ClapTrap <<" << this->getName() << ">> destructor called!" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (this->getEnergyPoints() > 0) {
		this->setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ClapTrap <<" << this->getName() << ">> attacks " << target << " causing " << this->getAttackDamage()
		          << " points of damage! " << std::endl;
	} else {
		std::cout << "ClapTrap <<" << this->getName() << ">> have no energy point to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap <<" << this->getName() << ">> takes " << amount << " points of damage!" << std::endl;
	this->setHitPoints(getHitPoints() - amount);
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->getEnergyPoints() > 0) {
		std::cout << "ClapTrap <<" << this->getName() << ">> is repaired by " << amount << " points" << std::endl;
		this->setEnergyPoints(getEnergyPoints() - 1);
		this->setHitPoints(getHitPoints() + amount);
	} else {
		std::cout << "ClapTrap <<" << this->getName() << ">> have no energy point to be repaired!" << std::endl;
	}
}

void ClapTrap::setName(std::string inputName) {
	std::cout << "ClapTrap " << inputName << " setName() called" << std::endl;
	this->name = inputName;
}

void ClapTrap::setHitPoints(int inputHitPoints) {
	std::cout << "ClapTrap <<" << this->name << ">> setHitPoints() called" << std::endl;
	this->hitPoints = inputHitPoints;
}

void ClapTrap::setEnergyPoints(int inputEnergyPoints) {
	std::cout << "ClapTrap <<" << this->name << ">> setEnergyPoints() called" << std::endl;
	this->energyPoints = inputEnergyPoints;
}

void ClapTrap::setAttackDamage(int inputAttackDamage) {
	std::cout << "ClapTrap <<" << this->name << ">> setAttackDamage() called" << std::endl;
	this->attackDamage = inputAttackDamage;
}

std::string ClapTrap::getName() const {
	std::cout << "ClapTrap <<" << this->name << ">> getName() called" << std::endl;
	return this->name;
}

int ClapTrap::getHitPoints() const {
	std::cout << "ClapTrap <<" << this->name << ">> getHitPoints() called" << std::endl;
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	std::cout << "ClapTrap <<" << this->name << ">> getEnergyPoints() called" << std::endl;
	return this->energyPoints;
}

int ClapTrap::getAttackDamage() const {
	std::cout << "ClapTrap <<" << this->name << ">> getAttackDamage() called" << std::endl;
	return this->attackDamage;
}