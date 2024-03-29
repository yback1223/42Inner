//
// Created by Yong Min Back on 2023/04/25.
//

#ifndef CPP_CONTACT_H
# define CPP_CONTACT_H

#include <iostream>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    ~Contact();
    Contact(
            std::string firstName,
            std::string lastName,
            std::string nickName,
            std::string phoneNumber,
            std::string darkestSecret
            );
	Contact(std::string contactFields[5]);

	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
};

#endif //CPP_CONTACT_H
