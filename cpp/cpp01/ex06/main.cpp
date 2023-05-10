/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:33:16 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:33:17 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(int ac, char **av) {
	int lvl = 0;
	Harl ex;
	std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac != 2) {
		std::cerr << "Error: Bad Arguments!" << std::endl;
		exit(1);
	}

	while (lvls[lvl] != av[1] && lvl < 5) {
		lvl++;
	}
	if (lvls[lvl] != av[1]) {
		std::cerr << "Error: Bad Arguments!" << std::endl;
		exit(1);
	}
	for (int i = lvl; i < 4; ++i) {
		ex.complain(lvls[i]);
	}
	std::cout << std::endl << "[ Probably complaining about insignificant problems ]" << std::endl;
}