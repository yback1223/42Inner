#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <exception>
# include "Data.hpp"

class Serializer {
	public:
		// 복사 생성자
		Serializer(const Serializer &copy);
		
		// 소멸자
		~Serializer();
		
		// 대입 연산자
		Serializer & operator=(const Serializer &assign);
		
		static uintptr_t serialize(Data * ptr);
		static Data * deserialize(uintptr_t raw);

	private:
		// 생성자
		Serializer();
};

#endif