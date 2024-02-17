#ifndef POSITIVE_INF_HPP
# define POSITIVE_INF_HPP

# include <exception>
# include "AType.hpp"

class PositiveInf: public virtual AType {
	public:
		// 생성자
		PositiveInf();

		// 복사 생성자
		PositiveInf(const PositiveInf &copy);
		
		// 소멸자
		virtual ~PositiveInf();
		
		// 대입 연산자
		PositiveInf & operator=(const PositiveInf &assign);

		// 예외 클래스 정의
		class PositiveInfException : public std::exception {
			virtual const char* what() const throw();
		};

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;
};

#endif