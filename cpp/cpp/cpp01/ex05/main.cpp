//
// Created by Yong Min Back on 2023/04/26.
//

#include "Harl.h"

int main() {
	Harl ex;
	std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i) {
		ex.complain(lvls[i]);
	}
}