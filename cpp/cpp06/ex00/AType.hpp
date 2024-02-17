#ifndef ATYPE_HPP
# define ATYPE_HPP

# include <string>

class AType {
	public:
		// 생성자
		AType();

		// 복사 생성자
		AType(const AType &copy);
		
		// 소멸자
		virtual ~AType();
		
		// 대입 연산자
		AType & operator=(const AType &assign);
		
		// 예외 클래스 정의
		class ImpossibleConversionException : public std::exception {
			virtual const char* what() const throw();
		};
		class NonDisplayableException : public std::exception {
			virtual const char* what() const throw();
		};

        virtual operator char() const = 0;
        virtual operator int() const = 0;
        virtual operator float() const = 0;
        virtual operator double() const = 0;

		static bool isPrintable(char c);
		static bool isDigit(char c);
};

#endif