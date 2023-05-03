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
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce();
	std::string GetName();
	void SetName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif //CPP_ZOMBIE_H
