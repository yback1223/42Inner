#include "AForm.hpp"

// 복사 생성자
AForm::AForm(const AForm &copy):
	_name(copy.getName()),
	_is_singed(copy.getSinged()),
	_signed_grade(copy.getSignedGrade()),
	_executed_grade(copy.getExecutedGrade())
{}

// 생성자
AForm::AForm(const std::string name, const int signed_grade, const int executed_grade):
	_name(name),
	_signed_grade(signed_grade),
	_executed_grade(executed_grade)
{
	this->_is_singed = false;
	if (this->_name.empty()) throw NoNameException();
	if (this->_signed_grade < 1 || this->_executed_grade < 1) throw GradeTooHighException();
	if (this->_signed_grade > 150 || this->_executed_grade > 150) throw GradeTooLowException();
}

// 소멸자
AForm::~AForm(){}

// 대입 연산자 오버로드
AForm & AForm::operator=(const AForm &assign) {
	if (this != &assign) _is_singed = assign.getSinged();
	return *this;
}

// Getters
const std::string AForm::getName() const {
	return _name;
}

bool AForm::getSinged() const {
	return _is_singed;
}

int AForm::getSignedGrade() const {
	return _signed_grade;
}

int AForm::getExecutedGrade() const {
	return _executed_grade;
}

void AForm::signForm(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signed_grade) throw GradeTooLowException();
	if(this->_is_singed) throw AlreadySignedException();
	this->_is_singed = true;
}

bool AForm::eligible(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->getExecutedGrade()) throw GradeTooLowException();
	if (!this->getSinged()) throw NotSignedException();
    return true;
}

// 예외
const char * AForm::GradeTooHighException::what() const throw() {
	return "Exception: Grade is too hight";
}

const char * AForm::GradeTooLowException::what() const throw() {
	return "Exception: Grade is too low";
}

const char * AForm::NoNameException::what() const throw() {
	return "Exception: Name is empty";
}

const char * AForm::NotSignedException::what() const throw() {
	return "Exception: The form is not signed";
}

const char * AForm::AlreadySignedException::what() const throw() {
	return "Exception: The form is already signed";
}


// Stream operators
std::ostream & operator<<(std::ostream &stream, const AForm &object) {
	stream << "" << object.getName() << ", form\n - Grade required to sign: " 
		<< object.getSignedGrade()
		<< "\n - Grade required to execute: " << object.getExecutedGrade() 
		<< "\n - Signed: ";
	if (object.getSinged())
		stream << "true" << std::endl;
	else
		stream << "false" << std::endl;
	return stream;
}