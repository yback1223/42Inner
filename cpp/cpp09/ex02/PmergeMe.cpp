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
	_tmp_deq.push_back(num);
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
		
		if (n > _size - 1) {
			if (_jacob[_jacob.size() - 1] != static_cast<int>(_size) - 1) _jacob.push_back(_size - 1);
			break;
		}
		_jacob.push_back(n);
	}
	_jacob.erase(_jacob.begin());
	_jacob.erase(_jacob.begin());
	// printJacob();
}

// vector
std::vector<std::pair<int, int> > PmergeMe::makePairsVec(std::vector<int> input_vec) {
	std::vector<std::pair<int, int> > result_pairs;
	std::vector<std::pair<int, int> > tmp_pairs;
	int tmp_size = input_vec.size();

	if (tmp_size % 2 != 0) {
		tmp_pairs.push_back(std::make_pair(-1, input_vec[input_vec.size() - 1]));
		input_vec.pop_back();
	}

	for (size_t i = 0; i < input_vec.size(); i += 2) {
		int big = input_vec[i] > input_vec[i + 1] ? input_vec[i] : input_vec[i + 1];
		int small = input_vec[i] <= input_vec[i + 1] ? input_vec[i] : input_vec[i + 1];
		result_pairs.push_back(std::make_pair(big, small));
	}

	if (tmp_size % 2 != 0) result_pairs.push_back(tmp_pairs[0]);
	return result_pairs;
}

void PmergeMe::insertSmallNumsVec(std::vector<int>& bigs, std::vector<int> smalls) {
	int insert_end_idx = 0;
	bool break_flag = false;

	for (int _jacob_idx = 0; _jacob_idx < static_cast<int>(_jacob.size()); _jacob_idx++) {
		int start_idx = _jacob[_jacob_idx];
		if (start_idx >= static_cast<int>(smalls.size())) start_idx = static_cast<int>(smalls.size()) - 1;

		for (int i = start_idx; i >= insert_end_idx; i--) {
			binarySearchInsertVec(bigs, 0, static_cast<int>(bigs.size()) - 1, smalls[i]);
		}
		if (break_flag) break;
		insert_end_idx = start_idx + 1;
	}
}

void PmergeMe::binarySearchInsertVec(std::vector<int> &vec, int l, int r, int target) {
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

std::vector<int> PmergeMe::recurVec(std::vector<int> recur_vec) {
	if (recur_vec.size() <= 2) {
    	return recur_vec;
    }

	std::vector<std::pair<int, int> > paired_vec = makePairsVec(recur_vec);
	std::vector<int> bigs, smalls;

	for (size_t i = 0; i < paired_vec.size(); i++) {
		int big_one = paired_vec[i].first;
		int small_one = paired_vec[i].second;

		if (big_one != -1) bigs.push_back(big_one);
		if (small_one != -1) smalls.push_back(small_one);	
	}
	std::vector<int> recurred_bigs = recurVec(bigs);
	std::vector<int> recurred_smalls = recurVec(smalls);

	insertSmallNumsVec(recurred_bigs, recurred_smalls);
	return recurred_bigs;
}

std::vector<int> PmergeMe::addLastVec(std::vector<int> recurred_vec) {
	if (last_num_flag) {
		binarySearchInsertVec(recurred_vec, 0, recurred_vec.size() - 1, last_num);
	}
	return recurred_vec;
}

// deque
std::deque<std::pair<int, int> > PmergeMe::makePairsDeq(std::deque<int> input_deq) {
        std::deque<std::pair<int, int> > result_pairs;
        std::deque<std::pair<int, int> > tmp_pairs;
        int tmp_size = input_deq.size();

        if (tmp_size % 2 != 0) {
            tmp_pairs.push_back(std::make_pair(-1, input_deq.back()));
            input_deq.pop_back();
        }

        for (size_t i = 0; i < input_deq.size(); i += 2) {
            int big = input_deq[i] > input_deq[i + 1] ? input_deq[i] : input_deq[i + 1];
            int small = input_deq[i] <= input_deq[i + 1] ? input_deq[i] : input_deq[i + 1];
            result_pairs.push_back(std::make_pair(big, small));
        }

        if (tmp_size % 2 != 0) result_pairs.push_back(tmp_pairs[0]);
        return result_pairs;
    }

void PmergeMe::insertSmallNumsDeq(std::deque<int>& bigs, std::deque<int> smalls) {
	int insert_end_idx = 0;
	bool break_flag = false;

	for (int _jacob_idx = 0; _jacob_idx < static_cast<int>(_jacob.size()); _jacob_idx++) {
		int start_idx = _jacob[_jacob_idx];
		if (start_idx >= static_cast<int>(smalls.size())) start_idx = static_cast<int>(smalls.size()) - 1;

		for (int i = start_idx; i >= insert_end_idx; i--) {
			binarySearchInsertDeq(bigs, 0, static_cast<int>(bigs.size()) - 1, smalls[i]);
		}
		if (break_flag) break;
		insert_end_idx = start_idx + 1;
	}
}

void PmergeMe::binarySearchInsertDeq(std::deque<int> &deq, int l, int r, int target) {
	int m;
	while (l <= r) {
		m = l + (r - l) / 2;

		if (m == 0 || deq[m - 1] < target) {
			if (m == static_cast<int>(deq.size()) || target < deq[m]) {
				deq.insert(deq.begin() + m, target);
				return;
			}
		}

		if (deq[m] < target) l = m + 1;
		else r = m - 1;
	}

	deq.insert(deq.begin() + l, target);
}

std::deque<int> PmergeMe::recurDeq(std::deque<int> recur_deq) {
	if (recur_deq.size() <= 2) {
		return recur_deq;
	}

	std::deque<std::pair<int, int> > paired_deque = makePairsDeq(recur_deq);
	std::deque<int> bigs, smalls;

	for (size_t i = 0; i < paired_deque.size(); i++) {
		int big_one = paired_deque[i].first;
		int small_one = paired_deque[i].second;

		if (big_one != -1) bigs.push_back(big_one);
		if (small_one != -1) smalls.push_back(small_one);
	}
	std::deque<int> recurred_bigs = recurDeq(bigs);
	std::deque<int> recurred_smalls = recurDeq(smalls);

	insertSmallNumsDeq(recurred_bigs, recurred_smalls);
	return recurred_bigs;
}

std::deque<int> PmergeMe::addLastDeq(std::deque<int> recur_deq) {
	if (last_num_flag) {
		binarySearchInsertDeq(recur_deq, 0, recur_deq.size() - 1, last_num);
	}
	return recur_deq;
}

std::vector<int> PmergeMe::getTempVec() {
	return _tmp_vec;
}

std::deque<int> PmergeMe::getTempDeq() {
	return _tmp_deq;
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

// vector 
std::string PmergeMe::printBeforeVec(const std::vector<int>& container) {
    std::ostringstream ss;
    ss << "Before:\t";
    size_t num = 0;
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (++num > 10) {
            ss << "\t [...]";
            break;
        }
        ss << ' ' << *it;
    }

    return ss.str();
}

std::string PmergeMe::printAfterVec(const std::vector<int>& container) {
    std::ostringstream ss;
    ss << "After:\t";
    size_t num = 0;
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (++num > 10) {
            ss << "\t [...]";
            break;
        }
        ss << ' ' << *it;
    }

    return ss.str();
}

// deque 
std::string PmergeMe::printBeforeDeq(const std::deque<int>& container) {
    std::ostringstream ss;
    ss << "Before:\t";
    size_t num = 0;
    for (std::deque<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (++num > 10) {
            ss << "\t [...]";
            break;
        }
        ss << ' ' << *it;
    }

    return ss.str();
}

std::string PmergeMe::printAfterDeq(const std::deque<int>& container) {
    std::ostringstream ss;
    ss << "After:\t";
    size_t num = 0;
    for (std::deque<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (++num > 10) {
            ss << "\t [...]";
            break;
        }
        ss << ' ' << *it;
    }

    return ss.str();
}


