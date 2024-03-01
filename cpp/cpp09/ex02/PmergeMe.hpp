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

		typedef std::vector<std::pair<int, int> > Container1;
		typedef std::deque<std::pair<int, int> > Container2;

		size_t size() const;
		Container1 & con1();
		Container2 & con2();

		void addNumberTmp(std::string lit);
		void makePairsAndPush();
		void makeJacobSthal();
		void printJacob();

		static void mergeCon1(Container1 & con, int l, int m, int r);
		static void mergeSortCon1(Container1 & con, int l, int r);
		static void moveAlone1(Container1 & con);
		std::vector<int> insertSmallNums1();
		void binarySearchInsert1(std::vector<int> & vec, int l, int r, int target);

		static void mergeCon2(Container2 & con, int l, int m, int r);
		static void mergeSortCon2(Container2 & con, int l, int r);
		static void moveAlone2(Container2 & con);
		std::deque<int> insertSmallNums2();
		void binarySearchInsert2(std::deque<int> & vec, int l, int r, int target);

		std::string printBefore();
		std::string printAfter(std::vector<int> resultVec);

		void startClock();
		void endClock();
		double getElapsedTime() const;
		void printProcessingTime(const std::string& containerType) const;


		std::vector<std::pair<int, int> > makePairs(std::vector<int> input_vec);
		void insertSmallNums(std::vector<int>& bigs, std::vector<int> smalls);
		std::vector<int> recur(std::vector<int> recur_vec);
		std::vector<int> _tmp_vec;
		std::vector<int> addLast(std::vector<int> recurred_vec);


	private:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe & operator=(const PmergeMe &assign);

		const size_t _size;
		size_t _pair_vec_size;
		Container1 _con1;
		Container2 _con2;
		std::vector<int> _jacob;
		int last_num;
		bool last_num_flag;

		clock_t startTime, endTime;

};

#endif