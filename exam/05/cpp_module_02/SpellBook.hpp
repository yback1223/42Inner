#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>
#include <map>

class ASpell;
class ATarget;

class SpellBook {
	private:
		SpellBook(const SpellBook& ref);
		SpellBook& operator=(const SpellBook& ref);
		std::map < std::string, ASpell* > spell_book;
	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string const & spell_name);
		ASpell* createSpell(std::string const & spell_name);
	
};

#endif