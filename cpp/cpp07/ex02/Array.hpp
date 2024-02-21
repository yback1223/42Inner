#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include "Array.tpp"

template<typename T>
class Array
{
	public:
		// 생성자
		Array();
		Array(unsigned int n);

		// 복사 생성자
		Array(const Array &copy);
		
		// 소멸자
		~Array();
		
		// 대입 연산자
		Array & operator=(const Array &assign);
		T & operator[](unsigned int i) const;
		
		size_t size() const;
		
	private:
		T * _data;
		size_t _size;
};

#endif
