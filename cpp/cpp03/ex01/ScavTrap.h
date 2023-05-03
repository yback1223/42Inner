//
// Created by Yong Min Back on 2023/04/30.
//

#ifndef CPP_SCAVTRAP_H
#define CPP_SCAVTRAP_H

#include "ClapTrap.h"
#include <iostream>

class ScavTrap : public ClapTrap {
private:
	bool gateMode;
public:
	ScavTrap();
	ScavTrap(std::string InputName);
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator=(const ScavTrap &copy);
	virtual ~ScavTrap();

	void guardGate();
	void attack(const std::string &target);
};


#endif //CPP_SCAVTRAP_H
