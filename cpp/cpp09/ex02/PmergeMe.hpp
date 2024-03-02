#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <sstream>
# include <vector>
# include <deque>
# include <ctime>
# include <iomanip>

class PmergeMe
{
	public:
		// 생성자
		PmergeMe(int size);
		
		// 소멸자
		~PmergeMe();
		
		// 예외 클래스 정의
		class WrongToken : public std::exception {
			virtual const char* what() const throw();
		};

		size_t size() const;

		void addNumberTmp(std::string lit);
		void makeJacobSthal();
		void printJacob();

		void binarySearchInsertVec(std::vector<int> & vec, int l, int r, int target);
		std::vector<std::pair<int, int> > makePairsVec(std::vector<int> input_vec);
		void insertSmallNumsVec(std::vector<int>& bigs, std::vector<int> smalls);
		std::vector<int> recurVec(std::vector<int> recur_vec);
		std::vector<int> addLastVec(std::vector<int> recurred_vec);

		void binarySearchInsertDeq(std::deque<int> & deq, int l, int r, int target);
		std::deque<std::pair<int, int> > makePairsDeq(std::deque<int> input_deq);
		void insertSmallNumsDeq(std::deque<int>& bigs, std::deque<int> smalls);
		std::deque<int> recurDeq(std::deque<int> recur_deq);
		std::deque<int> addLastDeq(std::deque<int> recurred_deq);

		std::vector<int> getTempVec();
		std::deque<int> getTempDeq();

		// utils
		std::string printBeforeVec(const std::vector<int>& container);
		std::string printAfterVec(const std::vector<int>& container);

		std::string printBeforeDeq(const std::deque<int>& container);
		std::string printAfterDeq(const std::deque<int>& container);
		
		void startClock();
		void endClock();
		double getElapsedTime() const;
		void printProcessingTime(const std::string& containerType) const;

	private:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe & operator=(const PmergeMe &assign);
		std::vector<int> _tmp_vec;
		std::deque<int> _tmp_deq;
		const size_t _size;
		size_t _pair_vec_size;
		std::vector<int> _jacob;
		int last_num;
		bool last_num_flag;
		clock_t startTime, endTime;
};

#endif