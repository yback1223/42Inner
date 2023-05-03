//
// Created by Yong Min Back on 2023/04/26.
//

#ifndef CPP_HUMANA_H
#define CPP_HUMANA_H

#include "Weapon.h"

class HumanA {
private:
	std::string name;
	Weapon &weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif //CPP_HUMANA_H
