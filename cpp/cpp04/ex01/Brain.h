/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:45:34 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 14:45:35 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_BRAIN_H
#define CPP_BRAIN_H

#include <iostream>

class Brain {
protected:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
	~Brain();

	void setIdea(int index, std::string type);
	std::string getIdea(int index) const;
};

#endif //CPP_BRAIN_H
