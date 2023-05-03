//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_WRONGCAT_H
#define CPP_WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &copy);
	WrongCat &operator=(const WrongCat &copy);
	virtual ~WrongCat();

	virtual void makeSound() const;
};

#endif //CPP_WRONGCAT_H
