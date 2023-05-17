/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:57:47 by yback             #+#    #+#             */
/*   Updated: 2023/05/17 15:57:50 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	virtual ~ScavTrap();

	void guardGate();
	void attack(const std::string &target);
};


#endif //CPP_SCAVTRAP_H
