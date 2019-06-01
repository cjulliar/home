#include "NCurses.hpp"

NCurses::NCurses()
{
	return ;
}

NCurses::NCurses(NCurses const &rhs) { *this = rhs; }

NCurses::~NCurses() {}

NCurses &
NCurses::operator=(NCurses const &) {

    return *this;
}

void
NCurses::render(std::vector<IMonitorModule *>::iterator it)
{
		std::cout << it[0]->OsInfo.getInfo() << std::endl;


}
