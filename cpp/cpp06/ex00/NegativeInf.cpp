#include "NegativeInf.hpp"

// 생성자
NegativeInf::NegativeInf() {}

// 복사 생성자
NegativeInf::NegativeInf(const NegativeInf &copy): AType() {
	(void) copy;
}

// 소멸자
NegativeInf::~NegativeInf() {}


// 대입 연산자
NegativeInf & NegativeInf::operator=(const NegativeInf &assign) {
	(void) assign;
	return *this;
}

// 예외 클래스 what() 메서드 구현
const char * NegativeInf::NegativeInfException::what() const throw() {
	return "-inf";
}

NegativeInf::operator char() const {
	throw ImpossibleConversionException();
}

NegativeInf::operator int() const {
	throw ImpossibleConversionException();
}

NegativeInf::operator float() const {
	throw NegativeInfException();
}

NegativeInf::operator double() const {
	throw NegativeInfException();
}
