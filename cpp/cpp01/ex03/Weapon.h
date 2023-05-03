//
// Created by Yong Min Back on 2023/04/26.
//

#ifndef CPP_WEAPON_H
#define CPP_WEAPON_H

#include <iostream>

class Weapon {
private:
	std::string type;
public:
	Weapon(std::string weaponType);
	~Weapon();

	const std::string getType() const;

	void setType(std::string newType);
};

#endif //CPP_WEAPON_H
