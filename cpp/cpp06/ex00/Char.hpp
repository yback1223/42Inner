#ifndef CHAR_HPP
# define CHAR_HPP

# include <string>
# include "AType.hpp"

class Char: public virtual AType
{
	public:
		// 생성자
		Char(std::string &lit);
		Char(const Char &copy);
		
		// 소멸자
		virtual ~Char();
		
		// 대입 연산자
		Char & operator=(const Char &assign);

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;
		
	private:
		Char();
		
		char _value;
};

#endif