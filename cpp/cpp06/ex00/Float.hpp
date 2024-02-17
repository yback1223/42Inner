#ifndef FLOAT_HPP
# define FLOAT_HPP

# include <string>
# include "AType.hpp"

class Float: public virtual AType {
	public:
		// 생성자
		Float(std::string &lit);

		// 복사 생성자
		Float(const Float &copy);
		
		// 소멸자
		virtual ~Float();
		
		// 대입 연산자
		Float & operator=(const Float &assign);

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;
		
	private:
		Float();

		float _value;
		
};

#endif