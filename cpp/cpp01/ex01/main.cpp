/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:29:45 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:29:46 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {

	Zombie zombie = Zombie("stackZombie");
	zombie.announce();

	Zombie *zombies = zombieHorde(9, "hordeZombie");
	for (int i = 0; i < 9; i++) {
		zombies[i].announce();
	}

	delete [] zombies;
//	system("leaks Zombie");
}