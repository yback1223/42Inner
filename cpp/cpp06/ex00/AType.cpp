#include "AType.hpp"

AType::AType() {}

// 생성자
AType::AType(const AType &copy) {
	(void) copy;
}

// 소멸자
AType::~AType() {}

// 대입 연산자
AType & AType::operator=(const AType &assign) {
	(void) assign;
	return *this;
}

bool AType::isPrintable(char c) {
    return 32 <= c && c < 127;;
}

bool AType::isDigit(char c) {
	return '0' <= c && c <= '9';
}

// Exceptions
const char * AType::ImpossibleConversionException::what() const throw() {
	return "impossible";
}

const char *AType::NonDisplayableException::what() const throw() {
    return "Non displayable";
}
