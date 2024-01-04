#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *hordezombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		hordezombie[i].setName(name);
	return (hordezombie);
}