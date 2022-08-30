#pragma once
#include <iostream>

class file {

	const std::string filePath = "contacts.txt";

public:

	file();

	void write(const std::string& str);
	void read(std::vector<std::string>& vec);
};