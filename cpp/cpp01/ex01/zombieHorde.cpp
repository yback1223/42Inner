/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:30:12 by yback             #+#    #+#             */
/*   Updated: 2023/05/12 14:51:36 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <sstream>

Zombie *zombieHorde(int N, std::string name) {
	if (N <= 0) {
		std::cerr << "Exception: Invalid N" << std::endl;
		exit(1);
	}
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		std::ostringstream oss;
		oss << i + 1;
		std::string tmpName = name;
		tmpName += oss.str();
		horde[i].setName(tmpName);
	}
	return horde;
}