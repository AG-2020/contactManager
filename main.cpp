// Aidan
#include "menu.hpp"

int main() {

	auto main = std::make_unique<menu>();

	while (!GetAsyncKeyState(VK_ESCAPE)) {
		main->checkInput();
		Sleep(100);
	}

	main.reset();
}