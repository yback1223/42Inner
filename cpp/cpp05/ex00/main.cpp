#include "Bureaucrat.hpp"

void print(std::string name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
	} catch (const std::exception& e) {
		std::cerr << name << "	" << e.what() << std::endl;
	}
}

void printInc(std::string name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
		bureaucrat.increaseGrade();
	} catch (const std::exception& e) {
		std::cerr << name << "	" << e.what() << std::endl;
	}
}

void printDec(std::string name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
		bureaucrat.decreaseGrade();
	} catch (const std::exception& e) {
		std::cerr << name << "	" << e.what() << std::endl;
	}
}

int main() {
		print("1", 0);
		print("2", 1);
		print("3", 75);
		print("4", 150);
		print("5", 151);
		printInc("6", 1);
		printDec("7", 150);
}
