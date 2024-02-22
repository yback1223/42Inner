#include <iostream>
#include "PmergeMe.hpp"

/// @ref https://github.com/decidedlyso/merge-insertion-sort/blob/master/README.md
int main(int argc, char *argv[]) {
	if (argc < 2 || argv == NULL) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe pm(argc - 1);
		for (int i = 1; i < argc; i++)
		{
			pm.push(argv[i]);
		}
		std::cout << "Before: " << PmergeMe::print(pm.con1()) << std::endl;
		std::clock_t time_vec = PmergeMe::bench(pm.con1(), PmergeMe::sortCon1);
		std::clock_t time_list = PmergeMe::bench(pm.con2(), PmergeMe::sortCon2);
		std::cout << "After:  " << PmergeMe::print(pm.con2()) << std::endl;

		std::cout << "Time to process a range of " << pm.size() << " elements with std::vector<int> : " << time_vec << " us" << std::endl;
		std::cout << "Time to process a range of " << pm.size() << " elements with std::list<int> : " << time_list << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}