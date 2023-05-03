//
// Created by Yong Min Back on 2023/04/26.
//

#ifndef CPP_HUMANB_H
#define CPP_HUMANB_H

#include <iostream>
#include "Weapon.h"

class HumanB {
private:
	std::string name;
	Weapon *weapon;

public:
	HumanB(std::string name);
	~HumanB();

	void setWeapon(Weapon &weapon);
	void attack() const;
};


#endif //CPP_HUMANB_H
