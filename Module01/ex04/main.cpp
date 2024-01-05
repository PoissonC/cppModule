#include <iostream>
#include <fstream>
#include <string>

void replaceAllOccurrences(std::string& source, const std::string& from, const std::string& to) {
    size_t startPos = 0;

	startPos = source.find(from, startPos);
    while (startPos != std::string::npos) {
        source.replace(startPos, from.length(), to);
        startPos += to.length();
		startPos = source.find(from, startPos);
    }
}

int main(int argc, char* argv[]) {
	//check arguments number
	if (argc != 4) {
		std::cout << "Wrong number of arguments." << std::endl;
		return 1;
	}

	// set up variables
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// check if file exists
	std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return 1;
    }

	// check if s1 is empty
	if (s1.empty()) {
		std::cerr << "s1 is empty." << std::endl;
		return 1;
	}

	// check if s2 is empty
	if (s2.empty()) {
		std::cerr << "s2 is empty." << std::endl;
		return 1;
	}

	// create new file
	std::string newFilename = filename + ".replace";
	std::ofstream outFile(newFilename);
	if (!outFile) {
		std::cerr << "Cannot create file: " << newFilename << std::endl;
		return 1;
	}

	// 
	std::string line;
	while (std::getline(inFile, line)) {
		replaceAllOccurrences(line, s1, s2);
		outFile << line << "\n";
	}

	inFile.close();
	outFile.close();
	return 0;
}
