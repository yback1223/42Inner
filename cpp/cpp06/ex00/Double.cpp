#include "Double.hpp"
#include <sstream>
#include <limits>

// 생성자
Double::Double(std::string &lit){
	std::stringstream ss(lit);

	ss >> _value;
	if (ss.fail()) throw ImpossibleConversionException();
}

// 복사 생성자
Double::Double(const Double &copy): AType() {
	*this = copy;
}

// 소멸자
Double::~Double() {}

// 대입 연산자
Double & Double::operator=(const Double &assign) {
	if (this != &assign) _value = assign._value;
	return *this;
}

Double::operator char() const {
	char c;

	if(0 > _value || std::numeric_limits<char>::max() < _value) throw ImpossibleConversionException();
	c = static_cast<char>(_value);
	if (!AType::isPrintable(c)) throw NonDisplayableException();
	return c;
}

Double::operator int() const {
	if(_value < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < _value) throw ImpossibleConversionException();
	return static_cast<int>(_value);
}

Double::operator float() const {
	if(_value > std::numeric_limits<float>::max() || _value < -std::numeric_limits<float>::max()) throw ImpossibleConversionException();
	return static_cast<float>(_value);
}

Double::operator double() const {
	return _value;
}
