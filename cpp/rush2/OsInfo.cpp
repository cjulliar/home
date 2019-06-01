#include "OsInfo.hpp"


OsInfo::OsInfo( void )
{
//	if (Monitor::getCurrent()->displayMode() == "ncurses")
		this->_display = new OsInfoNCurses;
//	else if (Monitor::getCurrent()->displayMode() == "qt5")
//		this->_display = NULL; //display qt5
//	else
//		throw(IMonitorModuleDisplay::Unknown());
}

OsInfo::~OsInfo( void )
{

}

void			OsInfo::updateModule( void )
{
	std::string string_info = Monitor::exec("hostinfo");
	std::string info = string_info.substr(string_info.find(':') + 4);
	this->_kernel = info.substr(0, info.find('\n'));

	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find('\n') + 1);

	this->_proc = info.substr(0, info.find('\n'));

	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find(':') + 2);

	this->_proc_type = info.substr(0, info.find('\n'));

	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find(':') + 2);	

	this->_memory = info.substr(0, info.find('\n'));

	info = info.substr(info.find('\n') + 1);
	info = info.substr(info.find(':') + 2);	

	this->_proc_set = info.substr(0, info.find('\n'));

	this->_display->display(*this);

}
