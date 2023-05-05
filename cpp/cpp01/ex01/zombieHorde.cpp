//
// Created by Yong Min Back on 2023/04/25.
//
#include "Zombie.h"
#include <sstream>

Zombie *zombieHorde(int N, std::string name) {
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		std::ostringstream oss;
		oss << i + 1;
		std::string tmpName = name;
		tmpName += oss.str();
		horde[i].setName(tmpName);
	}
	return horde;
}