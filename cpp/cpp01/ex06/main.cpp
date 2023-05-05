//
// Created by Yong Min Back on 2023/04/26.
//

#include "Harl.h"

int main(int ac, char **av) {
	int lvl = 0;
	Harl ex;
	std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac != 2) {
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		exit(1);
	}

	while (lvls[lvl] != av[1] && lvl < 5) {
		lvl++;
	}
	if (lvls[lvl] != av[1]) {
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		exit(1);
	}

	ex.complain(lvl);
}