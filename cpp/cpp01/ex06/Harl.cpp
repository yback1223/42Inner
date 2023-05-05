//
// Created by Yong Min Back on 2023/04/26.
//

#include "Harl.h"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "==DEBUG==" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "==INFO==" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "==WARNING==" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "==ERROR==" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(int level) {
	HarlFuncs funcs[4] = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
	};

	switch (level) {
		case 0:
			(this->*funcs[0])();
		case 1:
			(this->*funcs[1])();
		case 2:
			(this->*funcs[2])();
		case 3:
			(this->*funcs[3])();
	}
}