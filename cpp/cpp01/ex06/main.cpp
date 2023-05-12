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
	Harl ex;

	if (ac != ex.TWO) {
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		exit(ex.ERROR);
	}
	ex.complain(av[ex.FIRST]);
}