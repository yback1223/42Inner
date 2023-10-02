/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:45:29 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 14:49:57 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_CAT_H
#define CPP_CAT_H

#include "AAnimal.h"
#include "Brain.h"

class Cat : public AAnimal {
private:
	Brain *catBrain;
public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	virtual ~Cat();

	virtual void makeSound() const;
	void fillCatBrain();
	void getBrainEle(int index);
	Cat* clone() const;
};


#endif //CPP_CAT_H
