/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:22:41 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 14:22:42 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_WRONGCAT_H
#define CPP_WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	WrongCat &operator=(const WrongCat &copy);
	~WrongCat();
};

#endif //CPP_WRONGCAT_H
