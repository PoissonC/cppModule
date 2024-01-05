#pragma once

#include <iostream>
#include <string>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	
		// A structure to map strings to member function pointers
		struct Complaint {
			std::string level;
			void (Harl::*method)();
		};

	public:
		void	complain(std::string level);
};


