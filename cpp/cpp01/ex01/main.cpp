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

	Zombie zombie("stackZombie");
	zombie.announce();
	int num = 9;

	Zombie *zombies = zombieHorde(-1, "hordeZombie");
	for (int i = 0; i < num; i++) {
		zombies[i].announce();
	}

	delete [] zombies;
//	system("leaks Zombie");
}