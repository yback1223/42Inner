#include "Int.hpp"
#include <sstream>
#include <limits>

// 생성자
Int::Int(std::string &lit) {
	std::stringstream ss(lit);

	ss >> _value;
	if (ss.fail()) throw ImpossibleConversionException();
}

// 복사 생성자
Int::Int(const Int &copy): AType() {
	*this = copy;
}

// 소멸자
Int::~Int() {}


// 대입 연산자
Int & Int::operator=(const Int &assign) {
	if (this != &assign) _value = assign._value;
	return *this;
}

Int::operator char() const {
	char c;

	if(_value < 0 || std::numeric_limits<char>::max() < _value) throw ImpossibleConversionException();
	c = static_cast<char>(_value);
	if (!AType::isPrintable(c)) throw NonDisplayableException();
	return c;
}

Int::operator int() const {
	return _value;
}

Int::operator float() const {
	return static_cast<float>(_value);
}

Int::operator double() const {
	return static_cast<double>(_value);
}
