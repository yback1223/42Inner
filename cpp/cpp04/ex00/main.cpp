/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:21:43 by yback             #+#    #+#             */
/*   Updated: 2023/05/23 21:07:16 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Yong Min Back on 2023/05/01.
//

#include "Cat.h"
#include "Dog.h"
#include "Animal.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	WrongAnimal *wrongAnimal = new WrongCat();
	WrongCat *wrongCat = new WrongCat();
	
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	delete wrongCat;
	delete wrongAnimal;
	delete i;
	delete j;
	delete meta;

	// system("leaks Animal");
	return 0;
}