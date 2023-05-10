/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:29:07 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:29:11 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_ZOMBIE_H
#define CPP_ZOMBIE_H

#include <iostream>

class Zombie {
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
	std::string getName();
};

void randomChump(std::string name);

Zombie *newZombie(std::string name);

#endif //CPP_ZOMBIE_H
