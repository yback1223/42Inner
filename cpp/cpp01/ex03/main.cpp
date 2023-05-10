/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:32:18 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:32:19 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
#include "HumanA.h"
#include "HumanB.h"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB *anotherHumanB = new HumanB("HeapJim");
		anotherHumanB->setWeapon(club);
		anotherHumanB->attack();
		delete anotherHumanB;
	}
//	system("leaks Weapon");
	return 0;
}