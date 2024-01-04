#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	public:
		Zombie(const std::string& name = "");
		// Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	setName(const std::string& name);
	private:
		std::string	name;
};

#endif