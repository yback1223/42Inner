/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:29:29 by yback             #+#    #+#             */
/*   Updated: 2023/05/12 14:48:36 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <cstdlib>
#include <sstream>
#include <ctime>

void randomChump(std::string name) {
	std::stringstream ss;
    std::srand(static_cast<unsigned>(std::time(0)));

	int randomNumber = std::rand() % 100;
	ss << randomNumber;

	Zombie zombie(name.append(ss.str()));
	zombie.announce();
}