/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:33:16 by yback             #+#    #+#             */
/*   Updated: 2023/05/10 17:28:57 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int main(int ac, char **av) {
	int lvl = 0;
	Harl ex;
	std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (ac != 2) {
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		exit(1);
	}

	while (lvls[lvl] != av[1] && lvl < 3) {
		lvl++;
	}
	if (lvls[lvl] != av[1]) {
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		exit(1);
	}

	ex.complain(lvl);
}