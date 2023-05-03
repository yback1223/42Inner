//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_FRAGTRAP_H
#define CPP_FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string inputName);
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(const FragTrap &copy);
	virtual ~FragTrap();

	void highFivesGuys(void);
};

#endif //CPP_FRAGTRAP_H
