#ifndef DOUBLE_HPP
# define DOUBLE_HPP

# include <string>
# include "AType.hpp"

class Double: public virtual AType {
	public:
		// 생성자
		Double(std::string &lit);

		// 복사 생성자
		Double(const Double &copy);
		
		// 소멸자
		virtual ~Double();
		
		// 대입 연산자
		Double & operator=(const Double &assign);

        virtual operator char() const;
        virtual operator int() const;
        virtual operator float() const;
        virtual operator double() const;
		
	private:
		Double();

		double _value;	
};

#endif