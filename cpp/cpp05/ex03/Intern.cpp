#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// 생성자
Intern::Intern()
{}

// 복사 생성자
Intern::Intern(const Intern &copy) {
	(void) copy;
}

// 소멸자
Intern::~Intern()
{}

// 대입 연산자 오버라이드
Intern & Intern::operator=(const Intern &assign) {
	(void) assign;
	return *this;
}

// 각각의 form을 생성
AForm * scformConstructor(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm * rrformConstructor(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm * ppformConstructor(std::string target) {
	return new PresidentialPardonForm(target);
}

/**
 * @brief 이름이 AFormConstructor인 함수형 포인터 선언
 * 인자는 문자열
 */
typedef AForm * (*AFormConstructor)(std::string);

AForm *Intern::makeForm(std::string form, std::string target) const {
	const std::string FORMS[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};

	AFormConstructor FUNC_TABLE[3] = {
		scformConstructor,
		rrformConstructor,
		ppformConstructor,
	};

	AForm * result = NULL;
	for (size_t i = 0; i < 3; i++) {
		if (form == FORMS[i]) {
			result = FUNC_TABLE[i](target);
			std::cout << "Intern creates " << result->getName() << std::endl;
		}
	}
	if (result == NULL) throw NoSuchFormException();
	return result;
}

const char * Intern::NoSuchFormException::what() const throw() {
	return "The name of a form is not correct";
}