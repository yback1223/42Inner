#include "PmergeMe.hpp"

#include <iostream>
#include <algorithm>

// 생성자
PmergeMe::PmergeMe(int size): _size(size) {
	if (_size < 1) throw WrongToken();
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

void PmergeMe::addNumberTmp(std::string lit) {
    std::stringstream ss(lit);
    int num;

    for (std::string::iterator it = lit.begin(); it != lit.end(); ++it) {
        if (!std::isdigit(*it)) throw WrongToken();
    }
    ss >> num;
    if (ss.fail() || num < 0) throw WrongToken();
    if (_tmp_vec.size() >= _size) throw WrongToken();
    _tmp_vec.push_back(num);
}

void PmergeMe::makeJacobSthal() {
	size_t n = 0;
	_jacob.push_back(0);
	_jacob.push_back(1);
	last_num_flag = false;
	if (_tmp_vec.size() % 2 != 0) {
		last_num = _tmp_vec[_tmp_vec.size() - 1];
		last_num_flag = true;
		_tmp_vec.pop_back();
	}

	for (size_t i = 2;; i++) {
		n = _jacob[i - 1] + 2 * _jacob[i - 2];
		if (n >= _size) {
			_jacob.push_back(_size - 1);
			break;
		}
		_jacob.push_back(n);
	}
	_jacob.erase(_jacob.begin());
	_jacob.erase(_jacob.begin());
	printJacob();
}

std::vector<std::pair<int, int> > PmergeMe::makePairs(std::vector<int> input_vec) {
	std::vector<std::pair<int, int> > result_pairs;
	std::vector<std::pair<int, int> > tmp_pairs;
	int tmp_size = input_vec.size();
	if (tmp_size % 2 != 0) {
		tmp_pairs.push_back(std::make_pair(-1, input_vec[input_vec.size() - 1]));
		input_vec.pop_back();
	}
	for (size_t i = 0; i < input_vec.size(); i += 2) {
		// if (i == input_vec.size() - 1) result_pairs.push_back(std::make_pair(-1, input_vec[input_vec.size() - 1]));
		int big = input_vec[i] > input_vec[i + 1] ? input_vec[i] : input_vec[i + 1];
		int small = input_vec[i] <= input_vec[i + 1] ? input_vec[i] : input_vec[i + 1];
		result_pairs.push_back(std::make_pair(big, small));
	}
	if (tmp_size % 2 != 0) {
		result_pairs.push_back(tmp_pairs[0]);
	}
	return result_pairs;
}

void PmergeMe::insertSmallNums(std::vector<int>& bigs, std::vector<int> smalls) {
	for (size_t i = 0; i < smalls.size(); i++) {
		binarySearchInsert1(bigs, 0, static_cast<int>(bigs.size()) - 1, smalls[i]);
	}
}

void PmergeMe::binarySearchInsert1(std::vector<int> &vec, int l, int r, int target) {
    size_t m;
    while (l <= r) {
        m = l + (r - l) / 2;
    
        if (m == 0 || vec[m - 1] < target) {
            if (m == vec.size() || target < vec[m]) {
                vec.insert(vec.begin() + m, target);
                return;
            }
        }
        
        if (vec[m] < target) l = m + 1;
        else r = m - 1;
    }

    vec.insert(vec.begin() + l, target);
}

std::vector<int> PmergeMe::recur(std::vector<int> recur_vec) {
	if (recur_vec.size() <= 2) {
    	return recur_vec;
    }

	std::vector<std::pair<int, int> > paired_vec = makePairs(recur_vec);
	std::vector<int> bigs, smalls;

	for (size_t i = 0; i < paired_vec.size(); i++) {
		bigs.push_back(paired_vec[i].first);
		smalls.push_back(paired_vec[i].second);	
	}
	std::vector<int> recurred_bigs = recur(bigs);
	std::vector<int> recurred_smalls = recur(smalls);

	insertSmallNums(recurred_bigs, recurred_smalls);
    recurred_bigs.erase(std::remove(recurred_bigs.begin(), recurred_bigs.end(), -1), recurred_bigs.end());
	return recurred_bigs;
}

std::vector<int> PmergeMe::addLast(std::vector<int> recurred_vec) {
	if (last_num_flag) {
		binarySearchInsert1(recurred_vec, 0, recurred_vec.size() - 1, last_num);
	}
	return recurred_vec;
}

// Exceptions
const char * PmergeMe::WrongToken::what() const throw() {
	return "Error";
}

// utils
void PmergeMe::printJacob() {
    std::cout << "Jacob Nums = {";
    for (size_t i = 0; i < _jacob.size(); i++) {
        std::cout << _jacob[i] << " ";
    }
    std::cout << "}\n";
}

std::string PmergeMe::printBefore() {
    std::ostringstream ss;

    size_t num = 0;
	ss << "Before:	";
	if (last_num_flag) _tmp_vec.push_back(last_num);
    for (std::vector<int>::const_iterator it = _tmp_vec.begin(); it != _tmp_vec.end(); ++it) {
        if (++num > 10) {
            ss << "\t [...]";
            break;
        }
        ss << ' ' << *it;
    }
	if (last_num_flag) _tmp_vec.pop_back();

    return ss.str();
}

std::string PmergeMe::printAfter(std::vector<int> resultVec) {
    std::ostringstream ss;

    size_t num = 0;
	ss << "After:	";
    for (std::vector<int>::const_iterator it = resultVec.begin(); it != resultVec.end(); ++it) {
        if (++num > 10) {
            ss << "\t [...]";
            break;
        }
        ss << ' ' << *it;
    }
    return ss.str();
}

void PmergeMe::startClock() {
	startTime = clock();
}

void PmergeMe::endClock() {
	endTime = clock();
}

double PmergeMe::getElapsedTime() const {
    return static_cast<double>(endTime - startTime) * 10 / CLOCKS_PER_SEC;
}

void PmergeMe::printProcessingTime(const std::string& containerType) const {
    std::cout << "Time to process a range of " << _size 
              << " elements with " << containerType << ": "
              << std::fixed << std::setprecision(5) << getElapsedTime() << " us" << std::endl;
}