//
// Created by Yong Min Back on 2023/05/01.
//

#ifndef CPP_BRAIN_H
#define CPP_BRAIN_H

#include <iostream>

class Brain {
protected:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
	~Brain();

	void setIdea(int index, std::string type);
	std::string getIdea(int index) const;
};

#endif //CPP_BRAIN_H
