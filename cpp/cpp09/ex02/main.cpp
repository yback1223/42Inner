#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2 || argv == NULL) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe pm(argc - 1);
		for (int i = 1; i < argc; i++) {
			pm.addNumberTmp(argv[i]);
		}
		pm.makeJacobSthal();
		
		pm.startClock();
		std::cout << pm.printBeforeVec(pm.getTempVec()) << std::endl;
		std::vector<int> resultVec = pm.addLastVec(pm.recurVec(pm.getTempVec()));
		std::cout << pm.printAfterVec(resultVec) << std::endl;
		pm.endClock();
		pm.printProcessingTime("std::vector");

		pm.startClock();
		std::cout << pm.printBeforeDeq(pm.getTempDeq()) << std::endl;
		std::deque<int> resultDeq = pm.addLastDeq(pm.recurDeq(pm.getTempDeq()));
		std::cout << pm.printAfterDeq(resultDeq) << std::endl;
		pm.endClock();
		pm.printProcessingTime("std::vector");
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}