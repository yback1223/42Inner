//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_DOG_H
#define CPP_DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &copy);
	virtual ~Dog();

	virtual void makeSound() const;
};


#endif //CPP_DOG_H
