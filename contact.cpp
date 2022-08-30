#include <Windows.h>
#include <string>
#include "contact.hpp"

contact::contact() {
	f = std::make_unique<file>();

	//read contents of txt file if not empty and populate vector
}
contact::~contact() {
	f.reset();
}


void contact::contactsFn() {
	std::cout << "       Contacts:" << std::endl;
	std::cout << "-------------------------" << std::endl << std::endl;
	if (!contactList.empty()) {
		for (std::string i : contactList) {
			if (!i.empty())
				std::cout << i << std::endl;
		}
	}
	else std::cout << "No contacts yet, go add some!" << std::endl;
}

void contact::addEntryFn() {
	std::cout << "       Add entry:" << std::endl;
	std::cout << "-------------------------" << std::endl << std::endl;

	std::string firstName;
	std::string lastName;
	std::string newPhone;
	
	std::cout << "First name: ";
	std::cin >> firstName;

	std::cout << "Last name: ";
	std::cin >> lastName;

	std::cout << "Number: ";
	std::cin >> newPhone;

	const std::string str = std::string(firstName + " " + lastName + " - " + newPhone);

	contactList.push_back(str);

	f->write(str);

	std::cout << "Contact successfully added!" << std::endl;
}

void contact::deleteEntryFn() {
	std::cout << "Select entry you want to remove:" << std::endl;
	std::cout << "--------------------------------" << std::endl << std::endl;
	for (UINT i = 0; i < contactList.size(); i++) {
		if (!contactList[i].empty())
			std::cout << "[" << i << "] " << contactList[i].data() << std::endl;
	}
	

	// will crash if you list a number higher than the last index, need to implement vector.end instead 
	UINT option;
	std::cin >> option;
	if (!contactList[option].empty()) {
		contactList[option].erase();
		std::cout << "Successfully removed contact." << std::endl;
	}
	else
		std::cout << "you dumb?" << std::endl;
}

std::string contact::convertReadToStore(std::string& str) {
	//read  -> Aidan Latessa : 000-000-0000
	//store -> Aidan Latessa 

	return str;
}
