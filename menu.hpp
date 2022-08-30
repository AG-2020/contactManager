#pragma once
#include <Windows.h>
#include "contact.hpp"
#include "file.hpp"

class menu {
	const enum OPTIONS {
		MAINMENU,
		CONTACTS,
		ADDENTRY,
		DELETEENTRY
	};

	std::unique_ptr<contact> c;

	void clearScreen();

public:
	menu();
	~menu();

	void checkInput();
	void loadOption(UINT option);
	
};