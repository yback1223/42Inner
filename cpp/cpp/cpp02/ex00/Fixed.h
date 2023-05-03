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
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed &operator=(const Fixed &copy);
};


#endif //CPP02_FIXED_H
