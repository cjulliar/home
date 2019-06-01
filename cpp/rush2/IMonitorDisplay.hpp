#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"
#include <iostream>
#include <vector>
class IMonitorDisplay {
public:
	virtual         ~IMonitorDisplay() {}
	virtual void    render(std::vector<IMonitorModule *>::iterator it) = 0;
};

#endif /* IMONITORDISPLAY_HPP */
