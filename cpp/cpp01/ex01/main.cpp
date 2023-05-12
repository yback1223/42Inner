/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:29:45 by yback             #+#    #+#             */
/*   Updated: 2023/05/12 14:53:16 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

static int N = 6;

int main() {
	{
		Zombie zombie("stackZombie");
		zombie.announce();

		Zombie *zombies = zombieHorde(N, "hordeZombie");

		for (int i = 0; i < N; i++) {
			zombies[i].announce();
		}

		delete [] zombies;
	}

//	system("leaks Zombie");
}