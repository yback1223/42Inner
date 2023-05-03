//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_CAT_H
#define CPP_CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	virtual ~Cat();

	virtual void makeSound() const;
};


#endif //CPP_CAT_H
