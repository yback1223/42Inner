#include "SpellBook.hpp"

SpellBook::SpellBook(const SpellBook& ref) {
	*this = ref;
}

SpellBook& SpellBook::operator=(const SpellBook& ref) {
	if (this != &ref) {
		*this = ref;
	}
	return (*this);
}
		
SpellBook::SpellBook() {
}

SpellBook::~SpellBook() {
	std::map < std::string, ASpell* >::iterator it;
	for (it = spell_book.begin(); it != spell_book.end(); ++it) {
		delete it->second;
	}
	spell_book.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
	if (spell) {
		if (spell_book.find(spell->getName()) == spell_book.end()) {
			spell_book[spell->getName()] = spell->clone();
		}
	}
}

void SpellBook::forgetSpell(std::string const & spell_name) {
	std::map<std::string, ASpell*>::iterator it = spell_book.find(spell_name);
	if (it != spell_book.end()) {
		delete it->second;
		spell_book.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const & spell_name) {
	ASpell* tmp_spell = NULL;
	if (spell_book.find(spell_name) != spell_book.end()) {
		tmp_spell = spell_book[spell_name];
	}
	return (tmp_spell);
}
