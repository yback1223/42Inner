#include "Array.hpp"
#include <stdexcept>

// 생성자
template<typename T>
Array<T>::Array(): _data(new T[0]), _size(0)
{}

template<typename T>
Array<T>::Array(unsigned int n): _data(new T[n]), _size(n)
{}

// 복사 생성자
template<typename T>
Array<T>::Array(const Array<T> &copy): _data(new T[copy.size()]), _size(copy.size()) {
	for (size_t i = 0; i < _size; i++)
		_data[i] = copy._data[i];
}

// 소멸자
template<typename T>
Array<T>::~Array() {
	delete[] _data;
}

// 대입 연산자
template<typename T>
Array<T> & Array<T>::operator=(const Array<T> &assign) {
	if (this != &assign) {
		delete[] _data;
		_size = assign.size();
		_data = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_data[i] = assign._data[i];
	}
	return *this;
}

template<typename T>
T & Array<T>::operator[](unsigned int i) const {
	if (i >= _size) throw std::out_of_range("Out of range");
	return _data[i];
}

template<typename T>
size_t Array<T>::size() const {
	return _size;
}
