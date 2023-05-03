//
// Created by Yong Min Back on 2023/04/25.
//

#include "Contact.h"

Contact::Contact(
        std::string firstName,
        std::string lastName,
        std::string nickName,
        std::string phoneNumber,
        std::string darkestSecret
        ) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::Contact(std::string contactFields[5]) {
	this->firstName = contactFields[0];
	this->lastName = contactFields[1];
	this->nickName = contactFields[2];
	this->phoneNumber = contactFields[3];
	this->darkestSecret = contactFields[4];
}

Contact::Contact() {
	*this = Contact("", "", "", "", "");
}

Contact::~Contact() {}

std::string Contact::GetFirstName() {
	return this->firstName;
}

std::string Contact::GetLastName() {
	return this->lastName;
}

std::string Contact::GetNickName() {
	return this->nickName;
}

std::string Contact::GetPhoneNumber() {
	return this->phoneNumber;
}

std::string Contact::GetDarkestSecret() {
	return this->darkestSecret;
}