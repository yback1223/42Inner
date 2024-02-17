#ifndef NAN_HPP
# define NAN_HPP

# include <exception>
# include "AType.hpp"

class Nan: public virtual AType {
	public:
		// 생성자
		Nan();

		// 복사 생성자
		Nan(const Nan &copy);
		
		// 소멸자
		virtual ~Nan();
		
		// 대입 연산자
		Nan & operator=(const Nan &assign);

		// 예외 클래스 정의
		class NanException : public std::exception {
			virtual const char* what() const throw();
		};

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;
};

#endif