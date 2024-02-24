#include "PmergeMe.hpp"

#include <iostream>
#include <algorithm>

// 생성자
PmergeMe::PmergeMe(int size): _size(size) {
	if (_size < 1) throw WrongToken();
	_con1.reserve(_size);
	_pair_vec_size = _size % 2 == 0 ? _size / 2 : _size / 2 + 1;
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

void PmergeMe::makePairsAndPush() {
	std::cout << printBefore() << std::endl;
    for (size_t i = 0; i < _tmp_vec.size(); i += 2) {
        if (i + 1 == _tmp_vec.size()) {
            _con1.push_back(std::make_pair(-1, _tmp_vec[i]));
            _con2.push_back(std::make_pair(-1, _tmp_vec[i]));
        } else {
            int big = _tmp_vec[i] > _tmp_vec[i + 1] ? _tmp_vec[i] : _tmp_vec[i + 1];
            int small = _tmp_vec[i] <= _tmp_vec[i + 1] ? _tmp_vec[i] : _tmp_vec[i + 1];
            _con1.push_back(std::make_pair(big, small));
            _con2.push_back(std::make_pair(big, small));
        }
    }
    makeJacobSthal();
}

void PmergeMe::makeJacobSthal() {
	size_t n = 0;
	_jacob.push_back(0);
	_jacob.push_back(1);

	for (size_t i = 2;; i++) {
		n = _jacob[i - 1] + 2 * _jacob[i - 2];
		if (n >= _pair_vec_size) {
			_jacob.push_back(_pair_vec_size - 1);
			break;
		}
		_jacob.push_back(n);
	}
	_jacob.erase(_jacob.begin());
	_jacob.erase(_jacob.begin());
	// printJacob();
}

std::vector<int> PmergeMe::insertSmallNums1() {
    std::vector<int> resultVec;
    std::vector<int> smallNumVec;

    for (size_t i = 0; i < _pair_vec_size; ++i) {
        int poppedNum = _con1[i].first;
        int smallNum = _con1[i].second;
        smallNumVec.push_back(smallNum);
        if (poppedNum == -1) break;
        resultVec.push_back(poppedNum);
    }

    int searchEndIdx = 0;
    for (size_t i = 0; i < _jacob.size(); ++i) {
        int startIdx = _jacob[i];
        for (int j = startIdx; j >= searchEndIdx; --j) {
            if (j < static_cast<int>(smallNumVec.size())) {
                binarySearchInsert1(resultVec, 0, static_cast<int>(resultVec.size()) - 1, smallNumVec[j]);
            }
        }
        searchEndIdx = startIdx + 1;
    }
	std::cout << printAfter(resultVec) << std::endl;
    return resultVec;
}

std::deque<int> PmergeMe::insertSmallNums2() {
    std::deque<int> resultVec;
    for (std::deque<std::pair<int, int> >::iterator it = _con2.begin(); it != _con2.end(); ++it) {
        resultVec.push_back(it->first);
    }

    for (size_t i = 0; i < _jacob.size(); ++i) {
        int idx = _jacob[i];
        if (idx < static_cast<int>(_con2.size())) {
            std::deque<std::pair<int, int> >::iterator it = _con2.begin();
            std::advance(it, idx);
            binarySearchInsert2(resultVec, 0, static_cast<int>(resultVec.size()) - 1, it->second);
        }
    }

    return resultVec;
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

void PmergeMe::binarySearchInsert2(std::deque<int>& deq, int l, int r, int target) {
    int m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if ((m == 0 || deq[m - 1] < target) && (m == static_cast<int>(deq.size()) || target < deq[m])) {
            deq.insert(deq.begin() + m, target);
            return;
        }
        if (deq[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    deq.insert(deq.begin() + l, target);
}

void PmergeMe::mergeCon1(Container1 & con, int l, int m, int r) {
    int idxL, idxR, mergedIdx;
    int LRange = m - l + 1;
    int RRange = r - m;

    Container1 L(LRange), R(RRange);

    for (idxL = 0; idxL < LRange; idxL++) L[idxL] = con[l + idxL];
    for (idxR = 0; idxR < RRange; idxR++) R[idxR] = con[m + 1 + idxR];

    mergedIdx = l;
    idxL = 0;
    idxR = 0;

    while (idxL < LRange && idxR < RRange) {
        if (L[idxL].first <= R[idxR].first) con[mergedIdx++] = L[idxL++];
        else con[mergedIdx++] = R[idxR++];
    }
    while (idxL < LRange) con[mergedIdx++] = L[idxL++];
    while (idxR < RRange) con[mergedIdx++] = R[idxR++];
}

void PmergeMe::mergeCon2(Container2& con, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Container2 L, R;

    for (int i = 0; i < n1; i++) L.push_back(con[l + i]);
    for (int j = 0; j < n2; j++) R.push_back(con[m + 1 + j]);

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) con[k++] = L[i++];
        else con[k++] = R[j++];
    }

    while (i < n1) {
        con[k++] = L[i++];
    }
    while (j < n2) {
        con[k++] = R[j++];
    }
}

void PmergeMe::mergeSortCon1(Container1 & con, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		
		mergeSortCon1(con, l, m);
		mergeSortCon1(con, m + 1, r);

		mergeCon1(con, l, m, r);
	}
}

void PmergeMe::mergeSortCon2(Container2& con, int l, int r) {
    if (l >= r) {
        return; // 베이스 케이스
    }
    int m = l + (r - l) / 2;
    mergeSortCon2(con, l, m);
    mergeSortCon2(con, m + 1, r);
    mergeCon2(con, l, m, r);
}

void PmergeMe::moveAlone1(Container1 & con) {
    if (!con.empty() && con[0].first == -1) {
        con.push_back(std::pair<int, int>(-1, con[0].second));
        con.erase(con.begin());
    }
}

void PmergeMe::moveAlone2(Container2& con) {
    if (!con.empty() && con.front().first == -1) {
        con.push_back(con.front());
        con.pop_front();
    }
}

// Exceptions
const char * PmergeMe::WrongToken::what() const throw() {
	return "Error";
}

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
    for (std::vector<int>::const_iterator it = _tmp_vec.begin(); it != _tmp_vec.end(); ++it) {
        if (++num > 10) {
            ss << "\t [...]";
            break;
        }
        ss << ' ' << *it;
    }
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
    std::cout << "Time to process a range of " << _tmp_vec.size() 
              << " elements with " << containerType << ": "
              << std::fixed << std::setprecision(5) << getElapsedTime() << " us" << std::endl;
}




