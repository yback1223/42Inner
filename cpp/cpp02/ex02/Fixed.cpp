/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:10:18 by yback             #+#    #+#             */
/*   Updated: 2023/05/16 14:44:56 by yback            ###   ########seoul.kr  */
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

bool Fixed::operator>(const Fixed &boolean) const {
	return this->toFloat() > boolean.toFloat();
}

bool Fixed::operator<(const Fixed &boolean) const {
	return this->toFloat() < boolean.toFloat();
}

bool Fixed::operator>=(const Fixed &boolean) const {
	return this->toFloat() >= boolean.toFloat();
}

bool Fixed::operator<=(const Fixed &boolean) const {
	return this->toFloat() <= boolean.toFloat();
}

bool Fixed::operator==(const Fixed &boolean) const {
	return this->toFloat() == boolean.toFloat();
}

bool Fixed::operator!=(const Fixed &boolean) const {
	return this->toFloat() != boolean.toFloat();
}

Fixed Fixed::operator+(const Fixed &cal) const {
	return (Fixed) (this->toFloat() + cal.toFloat());
}

Fixed Fixed::operator-(const Fixed &cal) const {
	return (Fixed) (this->toFloat() - cal.toFloat());
}

Fixed Fixed::operator*(const Fixed &cal) const {
	return (Fixed) (this->toFloat() * cal.toFloat());
}

Fixed Fixed::operator/(const Fixed &cal) const {
    float divisor = cal.toFloat();
    if (divisor == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        exit(1);
    } else {
        return (Fixed) (this->toFloat() / divisor);
    }
}

Fixed Fixed::operator++(void) {
	this->val++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmpFixed(*this);
	this->val++;
	return (tmpFixed);
}

Fixed Fixed::operator--(void) {
	this->val--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmpFixed(*this);
	this->val--;
	return (tmpFixed);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a <= b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a >= b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a <= b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a >= b ? a : b);
}

std::ostream &operator<<(std::ostream &outstrm, const Fixed &fixed) {
	outstrm << fixed.toFloat();
	return (outstrm);
}