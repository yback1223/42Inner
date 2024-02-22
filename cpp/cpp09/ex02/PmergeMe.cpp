#include "PmergeMe.hpp"

#include <iostream>
#include <algorithm>

// 생성자
PmergeMe::PmergeMe(int size): _size(size) {
	if (_size < 1) throw WrongToken();
	_con1.reserve(_size);
}

// 소멸자
PmergeMe::~PmergeMe() {}

size_t PmergeMe::size() const {
	return _size;
}

PmergeMe::Container1 & PmergeMe::con1() {
	return _con1;
}

PmergeMe::Container2 & PmergeMe::con2() {
	return _con2;
}

void PmergeMe::push(std::string lit) {
	std::stringstream ss(lit);
	int num;

	for (std::string::iterator it = lit.begin(); it != lit.end(); ++it) {
		if (!std::isdigit(*it)) throw WrongToken();
	}
	ss >> num;
	if (ss.fail() || num < 0) throw WrongToken();
	if (_con1.size() >= _size || _con2.size() >= _size) throw WrongToken();
	_con1.push_back(num);
	_con2.push_back(num);
}

PmergeMe::Container1 PmergeMe::sortCon1(Container1 & con) {
	for (Container1::iterator it = con.begin(); it != con.end(); ++++it) {
		Container1::iterator next = it;
		std::advance(next, 1);
		if (next == con.end()) break ;
		if (*it > *next) std::iter_swap(it, next);
	}

	if (con.size() <= 2) return con;
	Container1 sorted;
	sorted.reserve(con.size() / 2);

	for (Container1::const_iterator it = ++con.begin(); it != con.end(); ++++it) {
		sorted.push_back(*it);

		Container1::const_iterator next = it;
		std::advance(next, 1);
		if (next == con.end()) break;
	}
	sorted = sortCon1(sorted);
	sorted.reserve(con.size());

	for (Container1::const_iterator it = con.begin(); it != con.end(); ++++it) {
		Container1::const_iterator pos = std::lower_bound(sorted.begin(), sorted.end(), *it);
		sorted.insert(pos, *it);

		Container1::const_iterator next = it;
		std::advance(next, 1);
		if (next == con.end()) break ;
	}
	return sorted;
	
	// std::sort(con.begin(), con.end());
	// return con;
}

PmergeMe::Container2 PmergeMe::sortCon2(Container2 & con) {
	for (Container2::iterator it = con.begin(); it != con.end(); ++++it) {
		Container2::iterator next = it;
		std::advance(next, 1);
		if (next == con.end()) break ;
		if (*it > *next) std::iter_swap(it, next);
	}

	if (con.size() <= 2) return con;
	Container2 sorted;
	for (Container2::const_iterator it = ++con.begin(); it != con.end(); ++++it) {
		sorted.push_back(*it);

		Container2::const_iterator next = it;
		std::advance(next, 1);
		if (next == con.end()) break ;
	}
	sorted = sortCon2(sorted);

	for (Container2::const_iterator it = con.begin(); it != con.end(); ++++it) {
		Container2::const_iterator pos = std::lower_bound(sorted.begin(), sorted.end(), *it);
		sorted.insert(pos, *it);

		Container2::const_iterator next = it;
		std::advance(next, 1);
		if (next == con.end()) break ;
	}
	return sorted;
}


// Exceptions
const char * PmergeMe::WrongToken::what() const throw() {
	return "Error";
}