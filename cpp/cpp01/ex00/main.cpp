/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:29:14 by yback             #+#    #+#             */
/*   Updated: 2023/05/10 17:32:43 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
	Zombie stackZombie("stackZombie");
	Zombie *heapZombie = newZombie("heapZombie");

	stackZombie.announce();
	heapZombie->announce();

	randomChump("randomZombie");

	delete heapZombie;
//	system("leaks Zombie");
}