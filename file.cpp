#include <fstream>
#include <filesystem>
#include "file.hpp"

// functionality not finished, able to write to file but not read correctly (cannot populate vector from txt but can populate txt from vector)

file::file() {
	try {
		if (!std::filesystem::exists(filePath)) {
			std::cout << "Could not find existing contact list, generating new one." << std::endl;
			std::fstream{ filePath };
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void file::write(const std::string& str) {
	try {
		auto stream = std::ofstream(filePath, std::ios::out | std::ios::app);
		stream << str << std::endl;
		stream.close();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void file::read(std::vector<std::string>& vec) {

	// could not figure out how to read file line by line before running out of time.

	/*try {
		auto stream = std::ifstream(filePath, std::ios::in);
		if (stream.is_open()) {
			for (std::string i : std::getline(stream, i)) {

			}
		}
		stream.close();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}*/
}