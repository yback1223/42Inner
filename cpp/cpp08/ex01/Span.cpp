#include "Span.hpp"
#include <algorithm>
#include <iterator>

// 생성자
Span::Span(unsigned int n): _size(n), _shortest_span(-1) {}

Span::Span(const Span &copy) {
	*this = copy;
}

// 소멸자
Span::~Span() {}

// 대입 연산자
Span & Span::operator=(const Span &assign) {
	if (this != &assign) {
		_size = assign._size;
		_list = assign._list;
		_shortest_span = assign._shortest_span;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (_list.size() >= _size) throw OverSizeException();

    std::list<int>::iterator pos;
    for (pos = _list.begin(); pos != _list.end(); ++pos) {
        if (*pos >= num) break;
    }
	std::list<int>::iterator iter = _list.insert(pos, num);

	if (iter != _list.begin()) {
		int left_span = *iter - *next(iter, -1);
		if (_shortest_span < 0 || _shortest_span > left_span) _shortest_span = left_span;
	}

	if (next(iter, 1) != _list.end()) {
	 	int right_span = *next(iter, 1) - *iter;
		if (_shortest_span < 0 || _shortest_span > right_span) _shortest_span = right_span;
	}
}

std::list<int>::iterator Span::next(std::list<int>::iterator iter, int n) {
	std::advance(iter, n);
    return iter;
}

int Span::shortestSpan() {
	if (_list.size() < 2) throw NoSpanFoundException();
    return _shortest_span;
}

int Span::longestSpan() {
	if (_list.size() < 2) throw NoSpanFoundException();
    return *_list.rbegin() - *_list.begin();
}

// 예외 케이스 what() 구현
const char * Span::OverSizeException::what() const throw() {
	return "Addition Failed: full size";
}
const char * Span::NoSpanFoundException::what() const throw() {
	return "No span found";
}
