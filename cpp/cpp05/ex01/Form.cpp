#include "Form.hpp"

// Constructors
Form::Form(const Form &copy) :
	_name(copy.getName()),
	_signed(copy.getSigned()),
	_signed_grade(copy.getSignedGrade()),
	_executed_grade(copy.getExecutedGrade()) {}

Form::Form(const std::string name, const int signed_grade, const int executed_grade) :
	_name(name),
	_signed_grade(signed_grade),
	_executed_grade(executed_grade)
{
	this->_signed = false;
	if (this->_name.empty())
		throw NameRequiredException();
	if (this->_executed_grade < 1 || this->_signed_grade < 1)
		throw GradeTooHighException();
	if (this->_executed_grade > 150 || this->_executed_grade > 150)
		throw GradeTooLowException();
}

// Destructor
Form::~Form() {}

// Operators
Form& Form::operator=(const Form &assign) {
	if (this != &assign)
		_signed = assign.getSigned();
	return *this;
}

// Getters & Setters
const std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getSignedGrade() const {
	return _signed_grade;
}

int Form::getExecutedGrade() const {
	return _executed_grade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signed_grade)
		throw GradeTooLowException();
	if (this->_signed == true)
		throw AlreadySignedException();
	this->_signed = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return "Error: Grade too high !!!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Error: Grade too low !!!";
}

const char* Form::NameRequiredException::what() const throw() {
	return "Error: Empty name !!!";
}

const char* Form::AlreadySignedException::what() const throw() {
	return "Error: Already signed !!!";
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