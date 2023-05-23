/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:20:29 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 14:20:30 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_CAT_H
#define CPP_CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	virtual ~Cat();

	virtual void makeSound() const;
};


#endif //CPP_CAT_H
