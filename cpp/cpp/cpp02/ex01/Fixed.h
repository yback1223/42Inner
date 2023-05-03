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
};

std::ostream &operator<<(std::ostream &outstrm, const Fixed &copy);

#endif //CPP02_FIXED_H
