//
// Created by Yong Min Back on 2023/04/25.
//

#ifndef CPP_ZOMBIE_H
#define CPP_ZOMBIE_H

#include <iostream>

class Zombie {
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	std::string getName();
};

void randomChump(std::string name);

Zombie *newZombie(std::string name);

#endif //CPP_ZOMBIE_H
