#pragma once

#include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon		*weapon;
		bool	is_weapon;

	public:
		HumanB(std::string name = "");
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &weapon);
};
