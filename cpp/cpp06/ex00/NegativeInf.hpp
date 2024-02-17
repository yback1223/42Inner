#ifndef NEGATIVE_INF_HPP
# define NEGATIVE_INF_HPP

# include <exception>
# include "AType.hpp"

class NegativeInf: public virtual AType {
	public:
		// 생성자
		NegativeInf();
		
		// 복사 생성자
		NegativeInf(const NegativeInf &copy);
		
		// 소멸자
		virtual ~NegativeInf();
		
		// 대입 연산자
		NegativeInf & operator=(const NegativeInf &assign);

		// 예외 클래스 정의
		class NegativeInfException : public std::exception {
			virtual const char* what() const throw();
		};

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;
};

#endif