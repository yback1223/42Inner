#include "Warlock.hpp"

Warlock::Warlock() {
}

Warlock::Warlock(const Warlock& ref) {
	*this = ref;
}

Warlock& Warlock::operator=(const Warlock& ref) {
	if (this != &ref) {
		name = ref.getName();
		title = ref.getTitle();
	}
	return (*this);
}

Warlock::Warlock(const std::string& ref_name, const std::string& ref_title) {
	name = ref_name;
	title = ref_title;
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const {
	return (name);
}

const std::string& Warlock::getTitle() const {
	return (title);
}

void Warlock::setTitle(const std::string ref_title) {
	title = ref_title;
}

void Warlock::introduce() const {
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}
