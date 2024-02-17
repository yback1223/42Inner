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
	// The code below is not requirements
	std::map<std::string, ASpell*>::iterator it;
	for (it = spell_book.begin(); it != spell_book.end(); ++it) {
		delete it->second;
	}
	spell_book.clear();
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

void Warlock::learnSpell(ASpell* spell) {
	if (spell) {
		if (spell_book.find(spell->getName()) == spell_book.end()) {
			spell_book[spell->getName()] = spell->clone();
		}
	}
}

void Warlock::forgetSpell(std::string spell_name) {
	std::map<std::string, ASpell*>::iterator it = spell_book.find(spell_name);
	if (it != spell_book.end()) {
		delete it->second;
		spell_book.erase(it);
	}
}

void Warlock::launchSpell(std::string spell_name, const ATarget& target) {
	if (spell_book.find(spell_name) != spell_book.end()) {
		spell_book[spell_name]->launch(target);
	}
}
