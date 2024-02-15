#include "Bureaucrat.hpp"

// 생성자
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {
	if (this->_grade < 1) throw GradeTooHighException();
	if (this->_grade > 150) throw GradeTooLowException();
	if (this->_name.empty()) throw NoNameException();
}

// 복사 생성자
Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName()) {
	*this = copy;
}

// 소멸자
Bureaucrat::~Bureaucrat() {}

// 대입 연산자 오버로드
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &assign) {
	if (this != &assign) _grade = assign.getGrade();
	return *this;
}

// Getters
const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::increaseGrade() {
	if (this->_grade <= 1) throw GradeTooHighException();
	--this->_grade;
}

void Bureaucrat::decreaseGrade() {
	if (this->_grade >= 150) throw GradeTooLowException();
	++this->_grade;
}

// 예외
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Exception: Grade too high !!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Exception: Grade too low !!!";
}

const char* Bureaucrat::NoNameException::what() const throw() {
	return "Exception: Empty name !!!";
}

// Stream operators
std::ostream& operator<<(std::ostream &stream, const Bureaucrat &object) {
	stream << "" << object.getName() << ", bureaucrat grade " << object.getGrade() << "." << std::endl;
	return stream;
}