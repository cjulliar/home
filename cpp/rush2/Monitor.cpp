#include "Gui.hpp"
#include "NCurses.hpp"
#include "Monitor.hpp"

Monitor* Monitor::_current = NULL;

Monitor::Monitor(bool gui) {

    if (gui)
    	std::cout << "Gui" << std::endl;
    //     _display = new Gui();
    else
        _display = new NCurses();

    Monitor::_current = this;
}

Monitor::Monitor(Monitor const &rhs) { *this = rhs; }

Monitor::~Monitor() {

    for (std::vector<IMonitorModule *>::const_iterator it = _modules.begin(); it != _modules.end(); it++) {
        delete *it;
    }

    delete _display;
}

Monitor &
Monitor::operator=(Monitor const &) {

    return *this;
}

Monitor*
Monitor::getCurrent( void ) { return Monitor::_current ; }

void
Monitor::display() {

	for (;;) {
		
		for (std::vector<IMonitorModule *>::iterator it = _modules.begin(); it != _modules.end(); it++)
		{
			(*it)->updateModule();
			// _display->render(*it); //dymaque cast
		}
		std::vector<IMonitorModule *>::iterator it = _modules.begin();
		_display->render(it);
		char c = getchar();
		if (c == 'q')
            break;
	}


/*
	pid_t pid;

	for ( std::list<IMonitorModule*>::iterator it = this->_modules.begin() ; it != this->_modules.end() ; it++ )
	{
		pid = fork();
		if ( pid == 0 )
		{
			signal(SIGQUIT, sigquit);
			while (this->active())
				(*it)->updateModule();
		}
		else if ( pid < 0 )
			throw(std::exception());
	}
	while (this->active())
	{
		char c = getchar();
		if (c == 'q')
		{
			kill(pid, SIGQUIT);
			this->deactivate();
			exit(0);
		}
	}*/
}
