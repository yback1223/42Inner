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

	WrongAnimal *wrongCat = new WrongCat();
	wrongCat->makeSound();

	delete wrongCat;
	delete i;
	delete j;
	delete meta;

	return 0;
}