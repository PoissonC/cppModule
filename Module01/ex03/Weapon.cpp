#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon() {
	std::cout << this->type <<" is destroyed.\n";
}

const std::string	&Weapon::getType() const {
	return (this->type);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}
