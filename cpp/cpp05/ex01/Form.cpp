#include "Form.hpp"

// 복사 생성자
Form::Form(const Form &copy) :
	_name(copy.getName()),
	_is_signed(copy.getSigned()),
	_signed_grade(copy.getSignedGrade()),
	_executed_grade(copy.getExecutedGrade()) {}

// 생성자
Form::Form(const std::string name, const int signed_grade, const int executed_grade) :
	_name(name),
	_signed_grade(signed_grade),
	_executed_grade(executed_grade)
{
	this->_is_signed = false;
	if (this->_name.empty()) throw NoNameException();
	if (this->_executed_grade < 1 || this->_signed_grade < 1) throw GradeTooHighException();
	if (this->_executed_grade > 150 || this->_executed_grade > 150) throw GradeTooLowException();
}

// 소멸자
Form::~Form() {}

// 대입 연산자 오버로드
Form& Form::operator=(const Form &assign) {
	if (this != &assign) _is_signed = assign.getSigned();
	return *this;
}

// Getters
const std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _is_signed;
}

int Form::getSignedGrade() const {
	return _signed_grade;
}

int Form::getExecutedGrade() const {
	return _executed_grade;
}

void Form::signForm(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signed_grade) throw GradeTooLowException();
	if (this->_is_signed) throw AlreadySignedException();
	this->_is_signed = true;
}

// 예외 클래스 구현
const char* Form::GradeTooHighException::what() const throw() {
	return "Exception: Grade too high !!!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Exception: Grade too low !!!";
}

const char* Form::NoNameException::what() const throw() {
	return "Exception: Empty name !!!";
}

const char* Form::AlreadySignedException::what() const throw() {
	return "Exception: Already signed !!!";
}

// Stream operators
std::ostream& operator<<(std::ostream &stream, const Form &object) {
	stream << "" << object.getName() << " Form"
		<< "\ngrade required to sign : " << object.getSignedGrade()
		<< "\ngrade required to execute : " << object.getExecutedGrade()
		<< "\nsigned status : ";
	if (object.getSigned())
		stream << "true" << std::endl;
	else
		stream << "false" << std::endl;
	return stream;
}