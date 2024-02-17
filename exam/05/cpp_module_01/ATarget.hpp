#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
	protected:
		ATarget(const ATarget& ref); // Assignment requirements
		ATarget& operator=(const ATarget& ref); // Assignment requirements
		std::string type;
	public:
		ATarget(const std::string& ref_type);
		virtual ~ATarget();
		const std::string& getType() const;
		virtual ATarget* clone() const = 0;
		void getHitBySpell(const ASpell& ref_spell) const;
};


#endif