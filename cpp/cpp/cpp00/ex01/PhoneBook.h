//
// Created by Yong Min Back on 2023/04/25.
//

#ifndef CPP_PHONEBOOK_H
#define CPP_PHONEBOOK_H

#include "Contact.h"

class PhoneBook {
private:
	Contact contacts[8];
    Contact CreateContact();
	std::string PrintOneContact(std::string contactInfo);
	void DisplayContact();
	bool ValidateInput(std::string inputIndex);
	int idx;

public:
    PhoneBook();
    ~PhoneBook();
	void AddContact();
	void SearchContact();
};


#endif //CPP_PHONEBOOK_H
