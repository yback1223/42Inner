#include "PositiveInf.hpp"

// 생성자
PositiveInf::PositiveInf() {}

// 복사 생성자
PositiveInf::PositiveInf(const PositiveInf &copy): AType() {
	(void) copy;
}

// 소멸자
PositiveInf::~PositiveInf() {}

// 대입 연산자
PositiveInf & PositiveInf::operator=(const PositiveInf &assign) {
	(void) assign;
	return *this;
}

// 예외 클래스 what() 메서드 구현
const char * PositiveInf::PositiveInfException::what() const throw() {
	return "+inf";
}

PositiveInf::operator char() const {
	throw ImpossibleConversionException();
}

PositiveInf::operator int() const {
	throw ImpossibleConversionException();
}

PositiveInf::operator float() const {
	throw PositiveInfException();
}

PositiveInf::operator double() const {
	throw PositiveInfException();
}
