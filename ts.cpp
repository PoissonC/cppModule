#include <iostream>
#include <iomanip>

int main() {
	std::string s = "123";

    std::cout << std::setw(10) << s.length();
    return 0;
}
