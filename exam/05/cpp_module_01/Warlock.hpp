#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class ASpell;
class ATarget;

class Warlock {
	private:
		Warlock();
		Warlock(const Warlock& ref);
		Warlock& operator=(const Warlock& ref);
		std::string name;
		std::string title;
		std::map < std::string, ASpell* > spell_book;
	public:
		Warlock(const std::string& ref_name, const std::string& ref_title);
		~Warlock();
		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string ref_title);
		void introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string spell_name);
		void launchSpell(std::string spell_name, const ATarget& target);
};

#endif