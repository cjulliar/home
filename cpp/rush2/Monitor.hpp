#ifndef MONITOR_HPP
# define MONITOR_HPP

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"
# include <vector>

class Monitor {
private:
    static Monitor*				    _current;
    IMonitorDisplay					*_display;
    std::vector<IMonitorModule *>	_modules;

public:
                                    Monitor(bool = false);
                                    Monitor(Monitor const &);
	                                ~Monitor();
    Monitor                         &operator=(Monitor const &);
	void							display();
	static Monitor*					getCurrent();
};

#endif /* MONITOR_HPP */
