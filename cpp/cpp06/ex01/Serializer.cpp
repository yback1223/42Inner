#include "Serializer.hpp"

// 복사 생성자
Serializer::Serializer(const Serializer &copy) {
	(void) copy;
}


// 소멸자
Serializer::~Serializer() {}

// 대입 연산자
Serializer & Serializer::operator=(const Serializer &assign) {
	(void) assign;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}