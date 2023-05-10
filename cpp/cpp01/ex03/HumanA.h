/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:30:40 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:30:41 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_HUMANA_H
#define CPP_HUMANA_H

#include "Weapon.h"

class HumanA {
private:
	std::string name;
	Weapon &weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif //CPP_HUMANA_H
