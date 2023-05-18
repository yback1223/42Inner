/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:58:16 by yback             #+#    #+#             */
/*   Updated: 2023/05/18 10:52:51 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/04/30.
//

#ifndef CPP_SCAVTRAP_H
#define CPP_SCAVTRAP_H

#include "ClapTrap.h"
#include <iostream>

class ScavTrap : public ClapTrap {
private:
	bool gateMode;
public:
	ScavTrap();
	ScavTrap(std::string InputName);
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator=(const ScavTrap &copy);
	~ScavTrap();

	void guardGate();
	void attack(const std::string &target);
};


#endif //CPP_SCAVTRAP_H
