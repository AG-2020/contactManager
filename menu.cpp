#include "menu.hpp"

menu::menu() {
    std::string username;
    const std::string title = "Phone Book";

    SetConsoleTitle(title.c_str());

    std::cout << "Welcome! What's your name?" << std::endl;
    std::cin >> username;
    username.append("'s " + title);
    SetConsoleTitle(username.c_str());

    c = std::make_unique<contact>();

    loadOption(MAINMENU);
}

menu::~menu() {
    c.reset();
}

void menu::checkInput() {
    UINT input;
    std::cin >> input;
    loadOption(input);
}

void menu::clearScreen() {

    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = { 0, 0 };

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacter(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

void menu::loadOption(UINT option) {

    clearScreen();

    switch (option) {
    case MAINMENU:
        std::cout << "       Main Menu:" << std::endl;
        std::cout << "-------------------------" << std::endl << std::endl;
        std::cout << "[1] View contacts" << std::endl;
        std::cout << "[2] Add new contact" << std::endl;
        std::cout << "[3] Remove contact" << std::endl;
        break;
    case CONTACTS:
        c->contactsFn();
        break;
    case ADDENTRY:
        c->addEntryFn();
        break;
    case DELETEENTRY:
        c->deleteEntryFn();
        break;
    default:
        std::cout << "Well someone can't follow directions... We aren't leaving until you get this right." << std::endl;
    }
    std::cout << std::endl << "-------------------------" << std::endl << std::endl;
    if (option != MAINMENU)
        std::cout << "[0] Return to main menu" << std::endl;
}
