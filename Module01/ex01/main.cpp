#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void) {
	Zombie *h1 = zombieHorde(10, "yu");
	for (int i = 0; i < 10; i++)
		h1[i].announce();
	Zombie *h2 = zombieHorde(20, "foo");
	for (int i = 0; i < 20; i++)
		h2[i].announce();
	delete []h1;
	delete []h2;
}
