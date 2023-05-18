//
// Created by Yong Min Back on 2023/05/18.
//

#ifndef CPP04_AANIMAL_H
#define CPP04_AANIMAL_H

#include <iostream>

class AAnimal {
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(std::string inputType);
	AAnimal(const AAnimal &copy);
	AAnimal &operator=(const AAnimal &copy);
	virtual ~AAnimal();

	virtual void makeSound() const = 0;
	std::string getType() const;
	void setType(std::string inputType);
	virtual AAnimal* clone() const = 0;
};


#endif //CPP04_AANIMAL_H
