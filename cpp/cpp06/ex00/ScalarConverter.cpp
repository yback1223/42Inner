#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include "Char.hpp"
#include "Double.hpp"
#include "Float.hpp"
#include "Int.hpp"
#include "Nan.hpp"
#include "NegativeInf.hpp"
#include "PositiveInf.hpp"

// 생성자
ScalarConverter::ScalarConverter() {}

// 복사 생성자
ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	(void) copy;
}

// 소멸자
ScalarConverter::~ScalarConverter() {}

// 대입 연산자
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign) {
	(void) assign;
	return *this;
}

AType * ScalarConverter::detectType(std::string &lit) {
	if (lit.length() == 0) throw AType::ImpossibleConversionException();
	if (lit.length() == 1 && AType::isPrintable(lit[0]) && !AType::isDigit(lit[0])) return new Char(lit);
	if (lit == "-inf" || lit == "-inff") return new NegativeInf();
	if (lit == "+inf" || lit == "inf" || lit == "+inff" || lit == "inff") return new PositiveInf();
	if (lit == "nan" || lit == "nanf") return new Nan();

	bool dot = false, last_f = false;
	for (size_t i = 0; i < lit.length(); i++) {
		if (AType::isDigit(lit[i]) || ((lit[i] == '-' || lit[i] == '+') && i == 0)) continue;
		else if (lit[i] == '.' && dot == false) dot = true;
		else if (lit[i] == 'f' && i == lit.length() - 1) last_f = true;
		else throw AType::ImpossibleConversionException();
	}

	if (last_f) {
		lit.pop_back();
		return new Float(lit);
	} else if (dot) return new Double(lit);
	else return new Int(lit);
}

void ScalarConverter::convert(std::string lit) {
	AType * type = NULL;

	try {
		type = detectType(lit);
	} catch(const AType::ImpossibleConversionException& e) {
		std::cout << "char: impossible" << std::endl
				<< "int: impossible" << std::endl
				<< "float: impossible" << std::endl
				<< "double: impossible" << std::endl;
		return ;
	}

	if (type) {
		try {
			char c = static_cast<char>(*type);
			std::cout << "char: '" << c << "'" << std::endl;
		} catch(const std::exception& e) {
			std::cout << "char: " << e.what() << std::endl;
		}

		try {
			int i = static_cast<int>(*type);
			std::cout << "int: " << i << std::endl;
		} catch(const std::exception& e) {
			std::cout << "int: " << e.what() << std::endl;
		}

		try {
			float f = static_cast<float>(*type);
			printFormattedFloat(f);
		} catch(const std::exception& e) {
			std::cout << "float: " << e.what() << "f" << std::endl;
		}
		
		try {
			double d = static_cast<double>(*type);
    	std::cout << "double: " << std::fixed << std::setprecision(1) << std::showpoint << d << std::endl;
		} catch(const std::exception& e) {
			std::cout << "double: " << e.what() << std::endl;
		}
		
		delete type;
	}
}

void ScalarConverter::printFormattedFloat(float value) {
    int intPart = static_cast<int>(value);
    float fracPart = value - intPart;

    if (fracPart == 0.0f) std::cout << "float: " << value << ".0f" << std::endl;
    else std::cout << "float: " << value << "f" << std::endl;
}

void ScalarConverter::printFormattedDouble(double value) {
    int intPart = static_cast<int>(value);
    double fracPart = value - intPart;

    if (fracPart == 0.0) std::cout << "double: " << value << ".0" << std::endl;
    else std::cout << "double: " << value << std::endl;
}
