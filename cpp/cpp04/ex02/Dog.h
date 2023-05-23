/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:45:44 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 14:55:53 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_DOG_H
#define CPP_DOG_H

#include "AAnimal.h"
#include "Brain.h"

class Dog : public AAnimal {
private:
	Brain *dogBrain;
public:
	Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &copy);
	virtual ~Dog();

	virtual void makeSound() const;
	void fillDogBrain();
	void getBrainEle(int index);
	Dog* clone() const;
};


#endif //CPP_DOG_H
