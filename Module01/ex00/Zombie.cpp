#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) {
	this->name = name;
	std::cout << "Zombie " << this->name << " has spwaned\n";
}

Zombie::~Zombie() {
	std::cout << this->name << " is destroyed.\n";
}


void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}