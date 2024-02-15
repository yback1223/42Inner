#include "ShrubberyCreationForm.hpp"
#include <fstream>

// 생성자
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{}

// 복사 생성자
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	AForm(copy),
	_target(copy._target)
{}

// 소멸자
ShrubberyCreationForm::~ShrubberyCreationForm()
{}

// 예외 클래스 구현
const char * ShrubberyCreationForm::UnplantableException::what() const throw() {
	return "The shrubbery cannot be plantable";
}

// 대입 연산자 오버로드
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign) {
	if (this != &assign) _target = assign._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	this->eligible(executor);
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (ofs.fail()) throw UnplantableException();
	ofs << "       _-_\n"
		<< "    /~~   ~~\\\n"
		<< " /~~         ~~\\\n"
		<< "{               }\n"
		<< " \\  _-     -_  /\n"
		<< "   ~  \\\\ //  ~\n"
		<< "_- -   | | _- _\n"
		<< "  _ -  | |   -_\n"
		<< "      // \\\\";
}