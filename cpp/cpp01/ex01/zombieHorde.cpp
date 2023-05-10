/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:30:12 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:30:14 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <sstream>

Zombie *zombieHorde(int N, std::string name) {
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