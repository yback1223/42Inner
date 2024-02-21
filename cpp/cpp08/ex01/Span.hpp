#ifndef SPAN_HPP
# define SPAN_HPP

#include <list>

class Span {
	public:
		// 생성자
		Span(unsigned int n);

		// 복사 생성자
		Span(const Span &copy);
		
		// 소멸자
		~Span();
		
		// 대입 연산자
		Span & operator=(const Span &assign);

		// 예외 클래스 정의
		class OverSizeException : public std::exception {
			virtual const char* what() const throw();
		};
		class NoSpanFoundException : public std::exception {
			virtual const char* what() const throw();
		};

		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		
		template<typename T>
		void addNumber(typename T::const_iterator begin, typename T::const_iterator end);

	private:
		Span();
		std::list<int>::iterator next(std::list<int>::iterator iter, int n);

		unsigned int _size;
		std::list<int> _list;
		int _shortest_span;
};

template<typename T>
void Span::addNumber(typename T::const_iterator begin, typename T::const_iterator end) {
	if (std::distance(begin, end) + _list.size() > _size)
		throw OverSizeException();
	for (; begin != end; ++begin) {
		addNumber(*begin);
	}
}

#endif