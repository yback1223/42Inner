#ifndef INT_HPP
# define INT_HPP

# include <string>
# include "AType.hpp"

class Int: public virtual AType {
	public:
		// 생성자
		Int(std::string &lit);

		// 복사 생성자
		Int(const Int &copy);
		
		// 소멸자
		virtual ~Int();
		
		// 대입 연산자
		Int & operator=(const Int &assign);

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;
		
	private:
		Int();

		int _value;		
};

#endif