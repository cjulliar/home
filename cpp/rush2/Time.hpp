#ifndef TIME_HPP
#define TIME_HPP

#include "imonitormodule.hpp"

#include "Time.ncurses.hpp"
#include "monitor.hpp"

#include <ctime>

class Time: public IMonitorModule
{
public:
	Time( void );
	virtual ~Time( void );

	virtual void		updateModule( void );

	std::time_t	const &	getTime( void ) const { return this->_time; }
private:
	std::time_t		_time;

};

#endif // TIME_HPP
