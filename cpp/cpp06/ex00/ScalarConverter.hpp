#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include "AType.hpp"

class ScalarConverter {
	public:
		// 복사 생성자
		ScalarConverter(const ScalarConverter &copy);
		
		// 소멸자
		~ScalarConverter();
		
		// 대입 연산자
		ScalarConverter & operator=(const ScalarConverter &assign);
		
		static void convert(std::string lit);

	private:
		// 생성자
		ScalarConverter();

		static AType * detectType(std::string &lit);
		static void printFormattedFloat(float value);
		static void printFormattedDouble(double value);
};

#endif