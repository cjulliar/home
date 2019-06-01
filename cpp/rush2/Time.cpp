#include "Time.hpp"


Time::Time( void )
{
	if (Monitor::getCurrent()->displayMode() == "ncurses")
		this->_display = new TimeNCurses;
	else if (Monitor::getCurrent()->displayMode() == "qt5")
		this->_display = NULL; //display qt5
	else
		throw(IMonitorModuleDisplay::Unknown());
}

Time::~Time( void )
{

}

void			Time::updateModule( void )
{
	this->_time = std::time(0);
	this->_display->display(*this);
}

