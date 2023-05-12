/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:33:11 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 18:33:12 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP_HARL_H
#define CPP_HARL_H

#include <iostream>

class Harl {
private:
	void debug();
	void info();
	void warning();
	void error();
public:
	static int FIRST;
	static int ERROR;
	static int TWO;
	Harl();
	~Harl();
	void complain(std::string level);
	};

typedef void (Harl::*HarlFuncs)(void);

#endif //CPP_HARL_H
