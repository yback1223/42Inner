#include "PresidentialPardonForm.hpp"
#include <iostream>

// 생성자
PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{}

// 복사 생성자
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
	AForm(copy),
	_target(copy._target)
{}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// 대입 연산자 오버로드
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign) {
	if (this != &assign) _target = assign._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	this->eligible(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}