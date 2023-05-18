//
// Created by Yong Min Back on 2023/05/01.
//

#include "Cat.h"
#include "Dog.h"
#include "Animal.h"
#include "WrongAnimal.h"
#include "WrongCat.h"
#include "Brain.h"

static int num = 87;

int main()
{
	Animal *fourAnimals[4];
	Animal *anotherFourAnimals[4];

	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			fourAnimals[i] = new Dog();
		} else {
			fourAnimals[i] = new Cat();
		}
	}


	for (int i = 0; i < 4; i++) {
			anotherFourAnimals[i] = fourAnimals[i]->clone();
		std::cout << anotherFourAnimals[i] << ", " << fourAnimals[i] << std::endl;
	}


	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			Dog *printDog = static_cast<Dog*>(fourAnimals[i]);
			Dog *printAnotherDog = static_cast<Dog*>(anotherFourAnimals[i]);

			printDog->getBrainEle(num);
			printAnotherDog->getBrainEle(num);
		} else {
			Cat *printCat = static_cast<Cat*>(fourAnimals[i]);
			Cat *printAnotherCat = static_cast<Cat*>(anotherFourAnimals[i]);
			
			printCat->getBrainEle(num);
			printAnotherCat->getBrainEle(num);
		}
	}

	for (int i = 0; i < 4; i++) {
		delete anotherFourAnimals[i];
	}

	for (int i = 0; i < 4; i++) {
		delete fourAnimals[i];
	}

	// system("leaks Animal");
	return 0;
}