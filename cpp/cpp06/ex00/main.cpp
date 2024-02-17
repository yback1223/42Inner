#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2 || argv == NULL || argv[1] == NULL) {
		std::cerr << "Arguments error!" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}