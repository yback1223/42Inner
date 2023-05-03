/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:09:42 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 19:09:43 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP02_FIXED_H
#define CPP02_FIXED_H

#include <iostream>

class Fixed {
private:
	int val;
	static const int bit = 8;
public:
	Fixed();
	Fixed(const Fixed &copy);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed &operator=(const Fixed &copy);
};


#endif //CPP02_FIXED_H
