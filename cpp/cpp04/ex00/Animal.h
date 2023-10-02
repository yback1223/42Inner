/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:19:07 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 14:19:08 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_ANIMAL_H
#define CPP_ANIMAL_H

#include <iostream>

class Animal {
protected:
	std::string type;
public:
	Animal();
	Animal(std::string inputType);
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
	virtual ~Animal();

	virtual void makeSound() const;
	std::string getType() const;
	void setType(std::string inputType);
};


#endif //CPP_ANIMAL_H
