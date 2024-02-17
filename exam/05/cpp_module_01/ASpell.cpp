#include "ASpell.hpp"

ASpell::ASpell(const ASpell& ref) {
	*this = ref;
}

ASpell& ASpell::operator=(const ASpell& ref) {
	if (this != &ref) {
		name = ref.getName();
		effects = ref.getEffects();
	}
	return (*this);
}
		
ASpell::ASpell(const std::string& ref_name, const std::string& ref_effects) {
	name = ref_name;
	effects = ref_effects;
}

ASpell::~ASpell() {
}

const std::string& ASpell::getName() const {
	return (name);
}

const std::string& ASpell::getEffects() const {
	return (effects);
}

void ASpell::launch(const ATarget& ref_target) const {
	ref_target.getHitBySpell(*this);
}
