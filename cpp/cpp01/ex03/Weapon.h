/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:32:30 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:32:31 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_WEAPON_H
#define CPP_WEAPON_H

#include <iostream>

class Weapon {
private:
	std::string type;
public:
	Weapon(std::string weaponType);
	~Weapon();

	const std::string getType() const;

	void setType(std::string newType);
};

#endif //CPP_WEAPON_H
