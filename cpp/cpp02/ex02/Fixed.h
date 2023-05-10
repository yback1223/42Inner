/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:10:23 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 19:10:24 by yback            ###   ########.fr       */
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
	Fixed(const int input);
	Fixed(const float input);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	Fixed &operator=(const Fixed &copy);

	bool operator>(const Fixed &boolean) const;
	bool operator<(const Fixed &boolean) const;
	bool operator>=(const Fixed &boolean) const;
	bool operator<=(const Fixed &boolean) const;
	bool operator==(const Fixed &boolean) const;
	bool operator!=(const Fixed &boolean) const;

	Fixed operator+(const Fixed &cal) const;
	Fixed operator-(const Fixed &cal) const;
	Fixed operator*(const Fixed &cal) const;
	Fixed operator/(const Fixed &cal) const;

	Fixed operator++(void);
	Fixed operator++(int);
	Fixed operator--(void);
	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &outstrm, const Fixed &copy);

#endif //CPP02_FIXED_H
