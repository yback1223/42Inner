#include "Bureaucrat.hpp"

void printResult(std::string name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void printResultInc(std::string name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
		bureaucrat.increaseGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void printResultDec(std::string name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
		bureaucrat.decreaseGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main() {
	printResult("A", 0);
	printResult("B", 1);
	printResult("C", 75);
	printResult("D", 150);
	printResult("E", 151);
	printResultInc("F", 1);
	printResultDec("G", 150);
}