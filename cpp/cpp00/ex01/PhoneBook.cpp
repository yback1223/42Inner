//
// Created by Yong Min Back on 2023/04/25.
//

#include "PhoneBook.h"
#include "Contact.h"
#include <string>

PhoneBook::PhoneBook() {
	idx = 0;
}

PhoneBook::~PhoneBook() {}

Contact PhoneBook::CreateContact() {
	std::string  contactFields[5];
	std::string  contactGuides[5];

	contactGuides[0] = "FirstName: ";
	contactGuides[1] = "LastName: ";
	contactGuides[2] = "NickName: ";
	contactGuides[3] = "PhoneNumber: ";
	contactGuides[4] = "Darkest Secret: ";
	for (int i = 0; i < 5; ++i) {
		std::cout << contactGuides[i];
		std::getline(std::cin, contactFields[i]);
		if (std::cin.fail()) {
			std::cout << "Exception reading input. Program Exit" << std::endl;
			exit(1);
		}
		while (contactFields[i] == "") {
			std::cout << contactGuides[i];
			std::getline(std::cin, contactFields[i]);
			if (std::cin.fail()) {
				std::cout << "Exception reading input. Program Exit" << std::endl;
				exit(1);
			}
		}
	}
	return Contact(contactFields);
}

void PhoneBook::AddContact() {
	contacts[idx % 8] = CreateContact();
	idx++;
	if (idx > 16) {
		idx -= 8;
	}
}

void PhoneBook::SearchContact() {
	std::cout << "|Index     |First Name|Last Name |Nick Name |" << std::endl;
	for (int i = 0; i < 8; ++i) {
		if (idx < 8 && idx == i) {
			break;
		}
		std::cout << "|         " << i + 1 << "|"
				<< PrintOneContact(contacts[i].getFirstName())
				<< PrintOneContact(contacts[i].getLastName())
				<< PrintOneContact(contacts[i].getNickName())
				<< std::endl;
	}
	if (idx != 0) {
		DisplayContact();
	}
}

std::string PhoneBook::PrintOneContact(std::string contactField) {
	int fieldLen = contactField.length();

	std::string oneLine = "";
	if (fieldLen == 10) {
		oneLine.append(contactField).append("|");
	} else if (fieldLen < 10) {
		for (int i = 0; i < 10 - fieldLen; ++i) {
			oneLine.append(" ");
		}
		oneLine.append(contactField).append("|");
	} else {
		oneLine.append(contactField.substr(0, 9)).append(".|");
	}
	return oneLine;
}

void PhoneBook::DisplayContact() {
	std::string input;
	int index;

	while (true) {
		std::cout << std::endl << "Input index(number only): ";
		std::getline(std::cin, input);
		if (std::cin.fail()) {
			std::cout << "Exception reading input. Program Exit" << std::endl;
			exit(1);
		}
		if (ValidateInput(input)) {
			continue;
		}
		index = std::atoi(input.c_str());
		std::cout << "First name: " << contacts[index - 1].getFirstName() << std::endl;
		std::cout << "Last name: " << contacts[index - 1].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index - 1].getNickName() << std::endl;
		std::cout << "Phone number: " << contacts[index - 1].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << contacts[index - 1].getDarkestSecret() << std::endl;
		break;
	}
}

bool PhoneBook::ValidateInput(std::string inputIndex) {
	const char *nullTermInput = inputIndex.c_str();
	int intInput = std::atoi(nullTermInput);
	std::string msg = "";

	if (inputIndex.length() != 1)
		msg = "The length of the input has to be 1!";
	else if (isdigit(inputIndex[0]) == 0)
		msg = "The input has to be an integer!";
	else if (!(1 <= intInput && intInput <= 8))
		msg = "The range of the input has to be 1 <= input <= 8!";
	else if (idx < 8 && idx < intInput)
		msg = "The input is over the number of the saved contacts!";

	if (msg != "") {
		std::cout << msg << std::endl;
		return true;
	}
	return false;
}