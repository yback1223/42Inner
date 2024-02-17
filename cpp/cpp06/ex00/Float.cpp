#include "Float.hpp"
#include <sstream>
#include <limits>

// 생성자
Float::Float(std::string &lit) {
	std::stringstream ss(lit);

	ss >> _value;
	if (ss.fail()) throw ImpossibleConversionException();
}

// 복사 생성자
Float::Float(const Float &copy): AType() {
	*this = copy;
}

// 소멸자
Float::~Float() {}


// 대입 연산자
Float & Float::operator=(const Float &assign) {
	if (this != &assign) _value = assign._value;
	return *this;
}

Float::operator char() const {
	char c;

	if(_value < 0 || std::numeric_limits<char>::max() < _value) throw ImpossibleConversionException();
	c = static_cast<char>(_value);
	if (!AType::isPrintable(c)) throw NonDisplayableException();
	return c;
}

Float::operator int() const {
	if(_value < std::numeric_limits<int>::min() || _value > std::numeric_limits<int>::max()) throw ImpossibleConversionException();
	return static_cast<int>(_value);
}

Float::operator float() const {
	return _value;
}

Float::operator double() const {
	return static_cast<double>(_value);
}
