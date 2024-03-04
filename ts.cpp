#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter {
public:
    // Delete the constructor to prevent instantiation
    ScalarConverter() = delete;

    static void convert(const std::string& literal) {
        try {
            if (literal.length() == 3 && literal.front() == '\'' && literal.back() == '\'') {
                // Handle char literals
                char c = literal[1];
                std::cout << "char: " << c << std::endl;
            } else if (literal.find('.') != std::string::npos || literal == "nan" || literal == "+inf" || literal == "-inf") {
                // Handle float and double literals, including pseudo literals
                if (literal.back() == 'f') {
                    float f = std::stof(literal);
                    printFloat(f);
                } else {
                    double d = std::stod(literal);
                    printDouble(d);
                }
            } else {
                // Handle int literals
                int i = std::stoi(literal);
                std::cout << "int: " << i << std::endl;
                printFloat(static_cast<float>(i));
                printDouble(static_cast<double>(i));
            }
        } catch (const std::invalid_argument& ia) {
            std::cerr << "Invalid argument: " << ia.what() << std::endl;
        } catch (const std::out_of_range& oor) {
            std::cerr << "Out of range: " << oor.what() << std::endl;
        }
    }

private:
    static void printFloat(float f) {
        if (std::isfinite(f)) {
            std::cout << "float: " << f << 'f' << std::endl;
        } else if (std::isnan(f)) {
            std::cout << "float: nanf" << std::endl;
        } else if (std::isinf(f)) {
            std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
        }
    }

    static void printDouble(double d) {
        if (std::isfinite(d)) {
            std::cout << "double: " << d << std::endl;
        } else if (std::isnan(d)) {
            std::cout << "double: nan" << std::endl;
        } else if (std::isinf(d)) {
            std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
        }
    }
};

int main() {
    ScalarConverter::convert("42");
    ScalarConverter::convert("-42");
    ScalarConverter::convert("4.2");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("'c'");
    
    return 0;
}
