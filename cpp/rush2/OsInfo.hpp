#ifndef OSINFO_HPP
#define OSINFO_HPP

#include "imonitormodule.hpp"

#include "OsInfo.ncurses.hpp"
#include "monitor.hpp"


class OsInfo: public IMonitorModule
{
public:
	OsInfo( void );
	virtual ~OsInfo( void );

	virtual void		updateModule( void );

	std::string	const &	getInfo( void ) const { return this->_info; }

	std::string	const &	getKernel( void ) const { return this->_kernel; }
	std::string	const &	getProc( void ) const { return this->_proc; }
	std::string	const &	getProcType( void ) const { return this->_proc_type; }
	std::string	const &	getMemory( void ) const { return this->_memory; }
	std::string	const &	getProcSet( void ) const { return this->_proc_set; }

private:
	std::string		_info;
	std::string		_kernel;
	std::string		_proc;
	std::string		_proc_type;
	std::string		_memory;
	std::string		_proc_set;

};

#endif // OSINFO_HPP
