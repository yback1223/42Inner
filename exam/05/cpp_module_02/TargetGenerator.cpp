#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(const TargetGenerator& ref) {
	*this = ref;
}
	
TargetGenerator& TargetGenerator::operator=(const TargetGenerator& ref) {
	if (this != &ref) {
		*this = ref;
	}
	return (*this);
}
		
TargetGenerator::TargetGenerator() {
}

TargetGenerator::~TargetGenerator() {
	std::map<std::string, ATarget*>::iterator it;
	for (it = target_list.begin(); it != target_list.end(); ++it) {
		delete it->second;
	}
	target_list.clear();
}

void TargetGenerator::learnTargetType(ATarget* target) {
	if (target) {
		// find != end 일 경우 segfault 발생하므로 주의
		if (target_list.find(target->getType()) == target_list.end()) {
			target_list[target->getType()] = target->clone();
		}
	}
}

void TargetGenerator::forgetTargetType(std::string const & ref_type) {
	std::map<std::string, ATarget*>::iterator it = target_list.find(ref_type);
	if (it != target_list.end()) {
		delete it->second;
		target_list.erase(it);
	}
}

ATarget* TargetGenerator::createTarget(std::string const & ref_type) {
	ATarget* tmp_target = NULL;
	if (target_list.find(ref_type) != target_list.end()) {
		tmp_target = target_list[ref_type];
	}
	return (tmp_target);
}
