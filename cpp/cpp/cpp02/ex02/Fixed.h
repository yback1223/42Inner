//
// Created by Yong Min Back on 2023/04/30.
//

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
