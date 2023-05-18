/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:58:34 by yback             #+#    #+#             */
/*   Updated: 2023/05/17 17:06:56 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/04/30.
//

#ifndef CPP_CLAPTRAP_H
#define CPP_CLAPTRAP_H

#include <iostream>

class ClapTrap {
private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setName(std::string inputName);
	void setHitPoints(int inputHitPoints);
	void setEnergyPoints(int inputEnergyPoints);
	void setAttackDamage(int inputAttackDamage);

	std::string	getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
};

#endif //CPP_CLAPTRAP_H
