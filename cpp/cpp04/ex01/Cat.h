//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_CAT_H
#define CPP_CAT_H

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
private:
	Brain *catBrain;
public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator=(const Cat &copy);
	virtual ~Cat();

	virtual void makeSound() const;
	void fillCatBrain();
	void getBrainEle(int index);
	Cat* clone() const;
};


#endif //CPP_CAT_H
