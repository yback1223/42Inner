#include "ATarget.hpp"

ATarget::ATarget(const ATarget& ref) {
	*this = ref;
}

ATarget& ATarget::operator=(const ATarget& ref) {
	if (this != &ref) {
		type = ref.getType();
	}
	return (*this);
}

ATarget::ATarget(const std::string& ref_type) {
	type = ref_type;
}

ATarget::~ATarget() {
}

const std::string& ATarget::getType() const {
	return (type);
}

void ATarget::getHitBySpell(const ASpell& ref_spell) const {
	std::cout << type << " has been " << ref_spell.getEffects() << "!" << std::endl;
}
