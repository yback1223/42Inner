/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:09:54 by yback             #+#    #+#             */
/*   Updated: 2023/05/03 19:09:55 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : val(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int input) {
	std::cout << "Int constructor called" << std::endl;
	this->val = input << this->bit;
}

Fixed::Fixed(const float input) {
	std::cout << "Float constructor called" << std::endl;
	this->val = (int)roundf(input * (1 << this->bit));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->val;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->val = raw;
}

Fixed &Fixed::operator=(const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		this->val = copy.getRawBits();
	}
	return *this;
}

int	Fixed::toInt(void) const {
	return (this->val >> this->bit);
}

float Fixed::toFloat(void) const {
	return ((float) this->val) / (1 << this->bit);
}

std::ostream &operator<<(std::ostream &outstrm, const Fixed &fixed) {
	outstrm << fixed.toFloat();
	return (outstrm);
}