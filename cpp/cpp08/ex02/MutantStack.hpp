#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

template<class T, class Container = std::deque<T> > 
class MutantStack : public std::stack<T, Container> {
	public:
		// 생성자
		MutantStack() {};

		// 소멸자
		~MutantStack() {};

		// 복사 생성자
		MutantStack(const MutantStack & copy) {
			*this = copy;
		};

		// 대입 연산자
		MutantStack & operator=(const MutantStack & assign) {
			if (this != &assign) std::stack<T, Container>::operator=(assign);
			return *this;
		};

		// iterators
		typedef typename Container::iterator                iterator;
		typedef typename Container::const_iterator          const_iterator;
		typedef typename Container::reverse_iterator        reverse_iterator;
		typedef typename Container::const_reverse_iterator  const_reverse_iterator;

		iterator begin() {
			return this->c.begin();
		};
		const_iterator begin() const {
			return this->c.begin();
		};
		iterator end() {
			return this->c.end();
		};
		const_iterator end() const {
			return this->c.end();
		};
		reverse_iterator rbegin() {
			return this->c.rbegin();
		};
		const_reverse_iterator rbegin() const {
			return this->c.rbegin();
		};
		reverse_iterator rend() {
			return this->c.rend();
		};
		const_reverse_iterator rend() const {
			return this->c.rend();
		};
	
		const_iterator cbegin() const {
			return this->c.cbegin();
		};
		const_iterator cend() const {
			return this->c.cend();
		};
		const_reverse_iterator crbegin() const {
			return this->c.crbegin();
		};
		const_reverse_iterator crend() const {
			return this->c.crend();
		};
};

#endif