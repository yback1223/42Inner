#include "Char.hpp"
#include <sstream>

// 생성자
Char::Char(std::string &lit) {
	std::stringstream ss(lit);

	ss >> _value;
	if (ss.fail()) throw ImpossibleConversionException();
}

// 복사 생성자
Char::Char(const Char &copy): AType() {
	*this = copy;
}

// 소멸자
Char::~Char() {}


// 대입 연산자
Char & Char::operator=(const Char &assign) {
	if (this != &assign) _value = assign._value;
	return *this;
}

Char::operator char() const {
	return _value;
}

Char::operator int() const {
	return static_cast<int>(_value);
}

Char::operator float() const {
	return static_cast<float>(_value);
}

Char::operator double() const {
	return static_cast<double>(_value);
}
