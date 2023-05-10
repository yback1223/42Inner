/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:32:49 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:32:50 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void Harl::complain(std::string level) {
	HarlFuncs funcs[4] = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
	};
	int lvl = -1;

	lvl = (level == "DEBUG") ? 0 : lvl;
	lvl = (level == "INFO") ? 1 : lvl;
	lvl = (level == "WARNING") ? 2: lvl;
	lvl = (level == "ERROR") ? 3: lvl;

	(this->*funcs[lvl])();
}