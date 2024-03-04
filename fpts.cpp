#include <iostream>
#include <string>
#include <cmath>
#include <string.h>

int main() {
	float f = 4224.4212312312313f;

	std::cout << f << std::endl;
	std::cout << roundf(f * 100) << std::endl;
	std::cout << roundf(f * (100)) / (100) << std::endl;

}