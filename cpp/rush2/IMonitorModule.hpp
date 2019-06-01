#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

class IMonitorModule {
public:
	virtual         ~IMonitorModule() {};
	virtual void	updateModule() = 0;
};

#endif /* IMONITORMODULE_HPP */
