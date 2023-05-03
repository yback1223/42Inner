//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_WRONGANIMAL_H
#define CPP_WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(std::string inputType);
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal &operator=(const WrongAnimal &copy);
	virtual ~WrongAnimal();

	virtual void makeSound() const;
	std::string getType() const;
	void setType(std::string inputType);
};


#endif //CPP_WRONGANIMAL_H
