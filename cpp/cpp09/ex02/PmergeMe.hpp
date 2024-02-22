#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <sstream>
# include <vector>
# include <list>
# include <ctime>

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

		typedef std::vector<int> Container1;
		typedef std::list<int> Container2;

		size_t size() const;
		Container1 & con1();
		Container2 & con2();

		void push(std::string lit);
		static Container1 sortCon1(Container1 & con);
		static Container2 sortCon2(Container2 & con);
		static Container1 mergeCon1(Container1 & left_con, Container1 & right_con);
		static Container2 mergeCon2(Container2 & left_con, Container2 & right_con);

		template<class T>
		static std::string print(const T& con);

		template<class T>
		static std::clock_t bench(T& con, T(*sort)(T &));

	private:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe & operator=(const PmergeMe &assign);

		const size_t _size;
		Container1 _con1;
		Container2 _con2;
};

template <class T>
std::string PmergeMe::print(const T &con) {
	std::ostringstream ss;

	size_t num = 0;
	for (typename T::const_iterator it = con.begin(); it != con.end(); ++it) {
		if (++num > 10) {
			ss << "\t [...]";
			break;
		}
		ss << '\t' << *it;
	}
	return ss.str();
}

template <class T>
std::clock_t PmergeMe::bench(T &con, T (*sort)(T &)) {
	std::clock_t start = std::clock();
	con = sort(con);
	std::clock_t end = std::clock();
	return end - start;
}

#endif