#include "Gui.hpp"

Gui::Gui() {}

Gui::Gui(Gui const &rhs) { *this = rhs; }

Gui::~Gui() {}

Gui &
Gui::operator=(Gui const &) {

    return *this;
}

// void
// Gui::render(std::vector<IMonitorModule *>::iterator it) {
// 	std::cout << it[0].getInfo() << std::endl;
// }
