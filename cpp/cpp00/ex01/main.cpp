//
// Created by Yong Min Back on 2023/04/25.
//
#include "PhoneBook.h"
#include <iostream>

int main() {
	PhoneBook phoneBook = PhoneBook();
	std::string input = "";

	while (true) {
		std::cout << "Command(EXIT, ADD, SEARCH): ";
		std::getline(std::cin, input);
		if (std::cin.fail()) {
			std::cout << "Error reading input. Program Exit." << std::endl;
			exit(1);
		}
		if (input == "EXIT") {
			std::cout << "Good Bye!" << std::endl;
			break;
		} else if (input == "ADD") {
			phoneBook.AddContact();
		} else if (input == "SEARCH") {
			phoneBook.SearchContact();
		} else {
			std::cout << "Only EXIT, ADD, SEARCH are allowed for input!" << std::endl;
		}
	}
}