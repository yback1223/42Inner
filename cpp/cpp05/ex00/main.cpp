#include "Bureaucrat.hpp"

void print(std::string name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
		// const로 예외 객체 불변성 보장
		// 참조로 받아서 불필요한 객체 복사 방지
	} catch (const std::exception& e) {
		// e.what()은 예외 객체에 대한 설명 문자열 반환
		std::cerr << e.what() << std::endl;
	}
}

void printInc(std::string name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
		bureaucrat.increaseGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void printDec(std::string name, int grade) {
	try {
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat;
		bureaucrat.decreaseGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int main() {
	print("A", 0);
	print("B", 1);
	print("C", 75);
	print("D", 150);
	print("E", 151);
	printInc("F", 1);
	printDec("G", 150);
}