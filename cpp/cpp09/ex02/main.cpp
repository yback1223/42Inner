#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2 || argv == NULL) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	try
	{
		// std::cout << argc << std::endl;
		PmergeMe pm(argc - 1);
		for (int i = 1; i < argc; i++) {
			pm.addNumberTmp(argv[i]);
		}
		pm.makePairsAndPush();

		pm.startClock();
		pm.mergeSortCon1(pm.con1(), 0, pm.con1().size() - 1);
		pm.moveAlone1(pm.con1());
		std::vector<int> resultVec = pm.insertSmallNums1();
		pm.endClock();
		pm.printProcessingTime("std::vector");


		pm.startClock();
		pm.mergeSortCon2(pm.con2(), 0, pm.con2().size() - 1);
		pm.moveAlone2(pm.con2());
		std::deque<int> resultDeq = pm.insertSmallNums2();
		pm.endClock();
		pm.printProcessingTime("std::deque");
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}