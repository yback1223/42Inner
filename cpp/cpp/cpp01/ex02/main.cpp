//
// Created by Yong Min Back on 2023/04/25.
//

#include <iostream>

int main() {
	std::string variable = "HI THIS IS BRAIN";
	std::string *stringPTR = &variable;
	std::string &stringREF = variable;

	std::cout << "=============================" << std::endl;
	std::cout << "           Address           " << std::endl;
	std::cout << "=============================" << std::endl;

	std::cout << "variable = " << &variable << std::endl;
	std::cout << "stringPTR = " << stringPTR << std::endl;
	std::cout << "stringREF = " << &stringREF << std::endl << std::endl;

	std::cout << "=============================" << std::endl;
	std::cout << "            Value            " << std::endl;
	std::cout << "=============================" << std::endl;

	std::cout << "variable = " << variable << std::endl;
	std::cout << "stringPTR = " << *stringPTR << std::endl;
	std::cout << "stringREF = " << stringREF << std::endl << std::endl;
}