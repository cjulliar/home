#ifndef GUI_HPP
# define GUI_HPP

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"
# include <vector>
#include <iostream>
class Gui : public IMonitorDisplay {
public:
                Gui();
                Gui(Gui const &);
    virtual     ~Gui();
    Gui         &operator=(Gui const &);
    // void        render(std::vector<IMonitorModule *>::iterator it);
};

#endif /* GUI_HPP */
