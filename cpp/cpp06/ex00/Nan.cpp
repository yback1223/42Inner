#include "Nan.hpp"

// 생성자
Nan::Nan() {}

// 복사 생성자
Nan::Nan(const Nan &copy): AType() {
	(void) copy;
}

// 소멸자
Nan::~Nan() {}


// 대입 연산자
Nan & Nan::operator=(const Nan &assign) {
	(void) assign;
	return *this;
}

// 예외 클래스 what() 메서드 구현
const char * Nan::NanException::what() const throw() {
	return "nan";
}

Nan::operator char() const {
	throw ImpossibleConversionException();
}

Nan::operator int() const {
	throw ImpossibleConversionException();
}

Nan::operator float() const {
	throw NanException();
}

Nan::operator double() const {
	throw NanException();
}
