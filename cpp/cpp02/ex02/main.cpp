/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:10:27 by yback             #+#    #+#             */
/*   Updated: 2023/05/16 14:46:06 by yback            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>

int main( void ) {
    Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "===MAIN===" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << "\n===Compare===" << std::endl;
    std::cout << "a < b is " << (a < b) << std::endl;
    std::cout << "a <= b is " << (a <= b) << std::endl;
    std::cout << "a > b is " << (a > b) << std::endl;
    std::cout << "a >= b is " << (a >= b) << std::endl;

    std::cout << "\n===Calculation===" << std::endl;
    std::cout << "a + b\n" << (a + b) << std::endl;
    std::cout << "a - b\n" << (a - b) << std::endl;
    std::cout << "a * b\n" << (a * b) << std::endl;
    std::cout << "a / b\n" << (a / b) << std::endl;
  	// std::cout << "b / a\n" << (b / a) << std::endl;

    std::cout << "\n===Prefix/Postfix operator===" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "++a = " << ++a << std::endl;

    std::cout << "a = " << a << std::endl;
    std::cout << "a-- = " << a-- << std::endl;
    std::cout << "a-- = " << a-- << std::endl;
    std::cout << "--a = " << --a << std::endl;
    std::cout << "--a = " << --a << std::endl;

	return 0;
}