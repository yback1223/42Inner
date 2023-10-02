#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw GradeTooLowException();
	if (this->_grade > 150)
		throw GradeTooHighException();
	if (this->_name.empty())
		throw NameRequiredException();;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName()) {
	*this = copy;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Operators
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &assign) {
	if (this != &assign)
		_grade = assign.getGrade();
	return *this;
}

// Getters & Setters
const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::increaseGrade() {
	if (this->_grade <= 1)
		throw GradeTooHighException();
	--this->_grade;
}

void Bureaucrat::decreaseGrade() {
	if (this->_grade >= 150)
		throw GradeTooLowException();
	++this->_grade;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << this->_name << " coudln't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Error: Grade too high !!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Error: Grade too low !!!";
}

const char* Bureaucrat::NameRequiredException::what() const throw() {
	return "Error: Empty name !!!";
}

// Stream operators
std::ostream& operator<<(std::ostream &stream, const Bureaucrat &object) {
	stream << "" << object.getName() << ", bureaucrat grade " << object.getGrade() << "." << std::endl;
	return stream;
}