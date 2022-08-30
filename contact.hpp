#pragma once
#include <iostream>
#include <vector>
#include "file.hpp"

class contact {
	std::vector<std::string> contactList;
	
	std::unique_ptr<file> f;

	std::string convertReadToStore(std::string& str);
public:
	contact();
	~contact();

	void contactsFn();
	void addEntryFn();
	void deleteEntryFn();
};