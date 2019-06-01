#ifndef NCURSES_HPP
# define NCURSES_HPP

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"
# include <vector>

#include <iostream>
class NCurses : public IMonitorDisplay {
public:
                NCurses();
                NCurses(NCurses const &);
    virtual     ~NCurses();
    NCurses     &operator=(NCurses const &);
    void        render(std::vector<IMonitorModule *>::iterator it);
};

#endif /* NCURSES_HPP */
