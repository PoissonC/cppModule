#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void) {
	Zombie *zb = newZombie("yu");
	zb->announce();
	delete zb;
	randomChump("foo");
}
