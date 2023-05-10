/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:32:02 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:32:04 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_HUMANB_H
#define CPP_HUMANB_H

#include <iostream>
#include "Weapon.h"

class HumanB {
private:
	std::string name;
	Weapon *weapon;

public:
	HumanB();
	HumanB(const std::string name);
	~HumanB();

	void setWeapon(Weapon &weapon);
	void attack() const;
};


#endif //CPP_HUMANB_H
