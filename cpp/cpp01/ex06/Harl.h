//
// Created by Yong Min Back on 2023/04/26.
//

#ifndef CPP_HARL_H
#define CPP_HARL_H

#include <iostream>

class Harl {
private:
	void debug();
	void info();
	void warning();
	void error();
public:
	Harl();
	~Harl();
	void complain(std::string level);
};

typedef void (Harl::*HarlFuncs)(void);

#endif //CPP_HARL_H
