#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <iostream>
#include <map>

class ATarget;

class TargetGenerator {
	private:
		TargetGenerator(const TargetGenerator& ref);
		TargetGenerator& operator=(const TargetGenerator& ref);
		std::map < std::string, ATarget* > target_list;
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget* target);
		void forgetTargetType(std::string const & ref_type);
		ATarget* createTarget(std::string const & ref_type);
};

#endif