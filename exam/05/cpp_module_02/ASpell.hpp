#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
	protected:
		ASpell(const ASpell& ref);
		ASpell& operator=(const ASpell& ref);
		std::string name;
		std::string effects;
	public:
		ASpell(const std::string& ref_name, const std::string& ref_effects);
		virtual ~ASpell();
		const std::string& getName() const;
		const std::string& getEffects() const;
		virtual ASpell* clone() const = 0;
		void launch(const ATarget& ref_target) const;
};

#endif