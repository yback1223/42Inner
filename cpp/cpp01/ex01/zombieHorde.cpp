//
// Created by Yong Min Back on 2023/04/25.
//
#include "Zombie.h"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		std::string tmpName = name;
		horde[i].setName(tmpName.append(std::to_string(i + 1)));
	}
	return horde;
}